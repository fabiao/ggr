CC=g++
CCFLAGS=-O2 -Wall -ggdb
CFILES=bat.cpp big_crab.cpp blade.cpp bonus.cpp bullet.cpp clam.cpp demon.cpp fire_grizzly.cpp fire.cpp firewall.cpp flash.cpp flower.cpp fog.cpp game.cpp ghost.cpp giant.cpp immobile.cpp insect.cpp little_devil.cpp magic.cpp magician.cpp main.cpp map.cpp mobile.cpp osd.cpp particle.cpp plant_mk2.cpp player.cpp pork.cpp rain.cpp red_arremer.cpp red_arremer_king.cpp rockfall.cpp skeleton.cpp snow.cpp sprite.cpp stalagmite.cpp thunder.cpp timer_A.cpp timer_B.cpp timer_C.cpp timer_D.cpp turtle.cpp util.cpp volture.cpp water.cpp weapon.cpp zombie.cpp
HFILES=bat.h big_crab.h blade.h bonus.h bullet.h clam.h demon.h fire_grizzly.h fire.h firewall.h flash.h flower.h fog.h game.h ghost.h giant.h immobile.h insect.h little_devil.h magic.h magician.h map.h mobile.h osd.h particle.h plant_mk2.h player.h pork.h rain.h red_arremer.h red_arremer_king.h rockfall.h skeleton.h snow.h sprite.h stalagmite.h thunder.h timer_A.h timer_B.h timer_C.h timer_D.h turtle.h util.h volture.h water.h weapon.h zombie.h 
OFILES=bat.o big_crab.o blade.o bonus.o bullet.o clam.o demon.o fire_grizzly.o fire.o firewall.o flash.o flower.o fog.o game.o ghost.o giant.o immobile.o insect.o little_devil.o magic.o magician.o main.o map.o mobile.o osd.o particle.o plant_mk2.o player.o pork.o rain.o red_arremer.o red_arremer_king.o rockfall.o skeleton.o snow.o sprite.o stalagmite.o thunder.o timer_A.o timer_B.o timer_C.o timer_D.o turtle.o util.o volture.o water.o weapon.o zombie.o
APP=ggr
INC_PATH=-I/usr/include/allegro -I./include
LIB_PATH=-L/usr/lib/x86_64-linux-gnu

LIBS=-lalleg

all: $(APP)

$(APP): $(OFILES) $(CFILES)
	$(CC) $(OFILES) $(CCFLAGS) $(LIB_PATH) $(LIBS) -o $(APP)

.cpp.o:
	$(CC) $(CCFLAGS) -O2 $(INC_PATH) -c $< -o $@

# REMEMBER to update debian/dirs if the system directories that we use are changed!!!
install: $(APP)
	mkdir -p $(DESTDIR)/opt/gigalomania # -p so we don't fail if folder already exists
	cp $(APP) $(DESTDIR)/opt/gigalomania
	cp readme.html $(DESTDIR)/opt/gigalomania
	cp -a gfx/ $(DESTDIR)/opt/gigalomania # -a need to copy permissions etc
	cp -a islands/ $(DESTDIR)/opt/gigalomania
	cp -a music/ $(DESTDIR)/opt/gigalomania
	cp -a sound/ $(DESTDIR)/opt/gigalomania
	# needed for DESTDIR option:
	mkdir -p $(DESTDIR)/usr/share/applications
	cp gigalomania.desktop $(DESTDIR)/usr/share/applications/
	#cp gigalomania_fullscreen.desktop $(DESTDIR)/usr/share/applications/
	# needed for DESTDIR option:
	mkdir -p $(DESTDIR)/usr/share/pixmaps
	cp gigalomania64.png $(DESTDIR)/usr/share/pixmaps/
# REMEMBER to update debian/dirs if the system directories that we use are changed!!!

uninstall:
	rm -rf $(DESTDIR)/opt/gigalomania # -f so we don't fail if folder doesn't exist
	rm -f $(DESTDIR)/usr/share/applications/gigalomania.desktop
	#rm -f $(DESTDIR)/usr/share/applications/gigalomania_fullscreen.desktop
	rm -f $(DESTDIR)/usr/share/pixmaps/gigalomania64.png

clean:
	rm -rf *.o
	rm -f $(APP)
