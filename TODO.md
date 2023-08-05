#### ⚙️ > todo
#### 🔧 > item currently in development
#### ✅ > implemented
#### ❌ > item discarded



### todo - items:
- ✅  textures
- ⚙️ documentation
- ⚙️ reset key
- ✅ smooth movement -> works great on mac, needs limiter on linux
- ✅ fisheye effect calculated
- ✅ > new approach max
- ❌ > upgrade to full dda --> nevermind, not doing it, discrete caster works fantastic as well

- ✅ debugging tools

	- ⏸️ > minimap --> might need player view indicator
	- ✅ > player_pos overlay
- ✅ wrong color at intersection of walls
- ✅ mirroring input keys with south-start

⏸️ refactoring -> mostly done, implementing new functions first


### to include fps counter and limiter:
	-	uncomment the 00_timing.c file
	-	in file deb_helpers.c include printf_fps(ol, vrs)
	-	proper free and allocate in deb_overlay.c


⚙️ Parsing part
### needs initial discussing how to implement:
- 🔧	basic error checking (partly implemented, will most likely need refactor)
- ⚙️ 	map struct to fill with information from map file
	- cast_drawer and cast_raycaster will need to get map information from map struct,
    - textures, floor and ceiling colors as well.