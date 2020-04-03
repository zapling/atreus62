current_dir = $(shell pwd)

compile:
		cd qmk_firmware && bin/./qmk compile -kb atreus62 -km zapling

flash:
		cd qmk_firmware && bin/./qmk flash -kb atreus62 -km zapling

qmk:
		[ ! -d "qmk_firmware" ] && git clone git@github.com:qmk/qmk_firmware.git
		ln -s "$(current_dir)/zapling" "$(current_dir)/qmk_firmware/keyboards/atreus62/keymaps/"
		cd qmk_firmware/ && make git-submodule