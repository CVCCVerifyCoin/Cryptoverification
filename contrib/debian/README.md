
Debian
====================
This directory contains files used to package cryptoverificationd/cryptoverification-qt
for Debian-based Linux systems. If you compile cryptoverificationd/cryptoverification-qt yourself, there are some useful files here.

## cryptoverification: URI support ##


cryptoverification-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install cryptoverification-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your cryptoverificationqt binary to `/usr/bin`
and the `../../share/pixmaps/cryptoverification128.png` to `/usr/share/pixmaps`

cryptoverification-qt.protocol (KDE)

