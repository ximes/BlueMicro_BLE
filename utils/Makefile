# keyboard := '{{default "luddite" .KEYBOARD}}'
# keyboardconfig := '{{default "single" .KEYBOARDCONFIG}}'
# fqbnfolder := '{{default "pca10056" .FQBNFOLDER}}'
# controllerfolder := '{{default "bluemicro840" .CONTROLLERFOLDER}}'
# hardwareconfig := '{{default .FQBNFOLDER .FQBNFOLDER}}/{{.CONTROLLERFOLDER}}'
# keymap := '{{default "default" .KEYMAP}}'
# firmwarepath := '{{default "../firmware" .FIRMWAREPATH}}'
# buildpath := '{{default "../.build" .BUILDPATH}}'
# sourcepath := '{{default .BUILDPATH .BUILDPATH}}/{{.KEYBOARD}}-{{.FQBNFOLDER}}-{{.CONTROLLERFOLDER}}-{{.KEYBOARDCONFIG}}-{{.KEYMAP}}'
# buildcachepath :=  '{{default "SOURCEPATH" .SOURCEPATH}}/.build-cache'
# outputpath :=  '{{default "SOURCEPATH" .SOURCEPATH}}/output'
# fqbn := '{{default "adafruit:nrf52:pca10056" .FQBN}}'

install: install-cli install-cores

install-cli :
	curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
	arduino-cli config init

install-cores :
	arduino-cli core update-index
	arduino-cli board listall
	arduino-cli core upgrade
	arduino-cli core install arduino:samd
	arduino-cli core search nrf52
	arduino-cli core install adafruit:nrf52
	arduino-cli core install community_nrf52:nrf52
	sudo chmod +x ~/Library/Arduino15/packages/community_nrf52/hardware/nrf52/0.1.21/tools/adafruit-nrfutil/macos/adafruit-nrfutil
	arduino-cli version

compile:
	arduino-cli compile --clean -t --fqbn community_nrf52:nrf52:bluemicro_nrf52840 --build-cache-path ../.build-cache ../firmware/firmware.ino  --output-dir ../.build/firmware \
	--libraries /Users/stefanofranzin/Library/Arduino15/packages/community_nrf52/hardware/nrf52/0.1.21/libraries \
	--libraries /Users/stefanofranzin/Library/Arduino15/packages/community_nrf52/hardware/nrf52/0.1.21/cores/nRF5 \

upload:
	arduino-cli upload -t --fqbn community_nrf52:nrf52:bluemicro_nrf52840  ../.build/firmware/firmware.ino.hex  --input-dir ../.build/firmware --port /dev/cu.usbmodem14401

convert:
	bsp_path=/Users/stefanofranzin/Library/Arduino15/packages/adafruit/hardware/nrf52
	python /Users/stefanofranzin/Library/Arduino15/packages/community_nrf52/hardware/nrf52/0.1.21/tools/uf2conv/uf2conv.py ../.build/firmware/firmware.ino.hex -c -f 0xADA52840 -o ../.build/firmware/firmware.ino.uf2

debug:
	arduino-cli debug -b community_nrf52:nrf52:bluemicro_nrf52840 ../firmware/firmware.ino --port /dev/cu.usbmodem14401