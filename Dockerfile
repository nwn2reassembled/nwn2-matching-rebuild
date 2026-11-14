# Open-source dependencies only. Proprietary inputs are runtime read-only mounts.
FROM debian:bookworm-slim@sha256:734a72b3d6142a71993b4bc580ca01d8ca687f77a2c422d96a961d3376b179bc AS base
RUN apt-get update && apt-get install -y --no-install-recommends \
    python3 python3-venv ca-certificates && \
    rm -rf /var/lib/apt/lists/*
RUN python3 -m venv /opt/venv
ENV PATH=/opt/venv/bin:$PATH PYTHONDONTWRITEBYTECODE=1 PYTHONUNBUFFERED=1
WORKDIR /app
COPY requirements.txt /app/requirements.txt
RUN pip install --no-cache-dir -r requirements.txt
RUN groupadd --gid 1000 worker && useradd --uid 1000 --gid 1000 --no-create-home worker && \
    mkdir /state /exchange /out /work && chown 1000:1000 /state /exchange /out /work
COPY tools /app/tools
COPY contributor-worker /app/contributor-worker
COPY tests /app/tests
COPY reference /app/reference

FROM base AS drafter
USER 1000:1000

FROM base AS runtime
USER root
RUN dpkg --add-architecture i386 && apt-get update && \
    apt-get install -y --no-install-recommends wine wine32:i386 wine64 \
    innoextract p7zip-full cabextract && \
    dpkg-query -W > /runtime-packages.txt && rm -rf /var/lib/apt/lists/*
USER 1000:1000
