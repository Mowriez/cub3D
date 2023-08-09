#### ⚙️ > todo
#### 🔧 > item currently in development
#### ✅ > implemented
#### ❌ > item discarded



### todo - items:
- ✅ correct freeing in all states of initialisation!!! (only alloc'd memory for main struct, map and texture-strings)
- ✅  textures
- ⚙️ documentation
- ✅ reset key -> not neccessary
- ✅ smooth movement -> works great with limiter
- ✅ fisheye effect calculated
- ✅ > new approach max
- ✅ > upgrade to full dda --> nevermind, not doing it, discrete caster works fantastic as well

- ✅ debugging tools

	- ✅ > minimap
	- ✅ > player_pos overlay
- ✅ wrong color at intersection of walls
- ✅ mirroring input keys with south-start

✅ refactoring


### to include fps counter and limiter:
	-	uncomment the 00_timing.c file
	-	in file deb_helpers.c include printf_fps(ol, vrs)
	-	proper free and allocate in deb_overlay.c


⚙️ Parsing part
### needs initial discussing how to implement:
- ✅	basic error checking (partly implemented, will most likely need refactor)
- ✅ 	map struct to fill with information from map file
	- ✅ cast_drawer and cast_raycaster will need to get map information from map struct,
    - ✅ textures, floor and ceiling colors as well.
	⚙️more checks: all 6 indicators set, correct file type, maybe check if opening tex files works
					✅additional number after colors
					⚙️close fd in every failcase in map initialiser
					✅spaces from clion?



✅ Memory management errors:

- Invalid read of size 4 ft_free (main.c:46) in main cub3d
-  definitely lost: 192 bytes in 4 blocks
-  ✅ Invalid read of size 1  -> error was in realloc, refactored function.


✅ Should be repaired for now, closed fd after freeing its address.
