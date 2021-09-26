current_dir = $(shell pwd)

# Clone and setup QMK
qmk:
		[ ! -d "qmk_firmware" ] && \
			git clone --recurse-submodules git@github.com:qmk/qmk_firmware.git \
		|| cd qmk_firmware && git pull

# Copy the latest firmware changes to qmk folder
copy-latest:
		[ -d "qmk_firmware/keyboards/atreus62/keymaps/zapling" ] \
			&& rm -rf qmk_firmware/keyboards/atreus62/zapling \
		|| echo ""
		cp -r zapling qmk_firmware/keyboards/atreus62/keymaps/.

# Compile the firmware using docker
compile: copy-latest
		cd qmk_firmware && util/docker_build.sh atreus62:zapling

# Compile and flash the firmware using docker
flash: copy-latest
		cd qmk_firmware && util/docker_build.sh atreus62:zapling:flash

build:
	docker build . -t qmk-zapling
