⚙️ > todo
🔧 > item currently in development
✅ > implemented
❌ > item discarded

####---todo - items---####
⚙️ textures
⚙️ parsing (false maps, paths to textures)
⚙️ documentation
⚙️ reset key
⏸️ smooth movement -> works great on mac, needs limiter on linux
✅ fisheye effekt decalculate
	✅> new approach max
	❌> upgrade to full dda --> nevermind, not doing it, discrete caster works fantastic as well
✅ debugging tools
	⏸️> minimap -->nneds player view indicator
	✅> player_pos overlay
✅ wrong color at intersection of walls
✅ mirroring input keys with south-start
⏸️ refactoring -> mostly done, implementing new functions first


to include fps counter and limiter:
-	uncomment the 00_timing.c file
-	in file deb_helpers.c include printf_fps(ol, vrs)
-	proper free and allocate in deb_overlay.c