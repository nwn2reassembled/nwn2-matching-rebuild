"""Offline native-unit tools. No models, compilers, ledger writes or publication."""
import argparse
import json
from pathlib import Path

from native_unit import digest, validate_inputs
from native_verify import verify_unit
from native_workflow import assess_plan, context_pack, coverage, project_scope, regression_plan


def load(path):
    return json.loads(Path(path).read_text())


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest='command', required=True)
    for name in ('validate', 'context', 'verify'):
        command = commands.add_parser(name)
        command.add_argument('--unit', required=True, type=Path)
        command.add_argument('--input-root', required=True, type=Path)
        if name == 'verify':
            command.add_argument('--object', required=True, type=Path)
            command.add_argument('--reference', required=True, type=Path)
            command.add_argument('--trusted-pins', required=True, type=Path)
            command.add_argument('--approved-unit-sha256', required=True)
    plan = commands.add_parser('plan')
    plan.add_argument('--before', required=True, type=Path)
    plan.add_argument('--after', required=True, type=Path)
    plan.add_argument('--changed', nargs='*', default=[])
    plan.add_argument('--discovery-uncertain', action='store_true')
    assess = commands.add_parser('assess')
    assess.add_argument('--plan', required=True, type=Path)
    assess.add_argument('--units', required=True, type=Path)
    assess.add_argument('--receipts', required=True, type=Path)
    scope = commands.add_parser('coverage')
    scope.add_argument('--items', required=True, type=Path)
    scope.add_argument('--ranges', required=True, type=Path)
    project = commands.add_parser('project-scope')
    project.add_argument('--root', required=True, type=Path)
    args = parser.parse_args()
    if args.command in ('validate', 'context', 'verify'):
        unit = load(args.unit)
        validate_inputs(unit, args.input_root)
        if args.command == 'validate':
            result = {'state': 'consistent-context-not-independent-proof', 'unit_sha256': digest(unit)}
        elif args.command == 'context':
            result = context_pack(unit)
        else:
            result = verify_unit(unit, args.object.read_bytes(), args.reference, args.input_root,
                                 load(args.trusted_pins), args.approved_unit_sha256)
    elif args.command == 'plan':
        result = regression_plan(load(args.before), load(args.after), args.changed, args.discovery_uncertain)
    elif args.command == 'assess':
        result = assess_plan(load(args.plan), load(args.units), load(args.receipts))
    elif args.command == 'coverage':
        result = coverage(load(args.items), load(args.ranges))
    else:
        result = project_scope(args.root)
    print(json.dumps(result, indent=2, sort_keys=True))
    if result.get('all_regions_exact') is False or result.get('state') == 'integration-regression':
        raise SystemExit(1)


if __name__ == '__main__':
    main()
