FROM qmkfm/qmk_cli

RUN qmk clone

COPY . /qmk_firmware/keyboards/atreus62/keymaps/.

WORKDIR /qmk_firmware

RUN qmk compile -kb atreus62 -km zapling
