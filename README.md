Webkit Embedded
===============
URL: https://gitlab.freedesktop.org/gstreamer/gst-plugins-bad/tree/master/ext/wpe
The wpesrc element is used to produce a video texture representing a web page rendered off-screen by WPE.

Install Build-Dependencies
--------------------------
```
sudo apt install -y build-essential autoconf pkg-config libtool gstreamer1.0-tools libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-gl1.0-0

mkdir $HOME/wpe
mkdir $HOME/wpe/installed
cd $HOME/wpe
```

```
wget https://wpewebkit.org/releases/libwpe-1.1.0.tar.xz
tar xvaf libwpe-1.1.0.tar.xz
cd libwpe-1.1.0

cmake -DCMAKE_INSTALL_PREFIX=$HOME/wpe/installed/ -DCMAKE_BUILD_TYPE=RelWithDebInfo -GNinja
ninja
ninja install
```

```
cd $HOME/wpe
wget https://wpewebkit.org/releases/wpebackend-fdo-1.1.0.tar.xz
tar xvaf wpebackend-fdo-1.1.0.tar.xz
cd wpebackend-fdo-1.1.0

cmake -DCMAKE_INSTALL_PREFIX=$HOME/wpe/installed/ -DCMAKE_BUILD_TYPE=RelWithDebInfo -GNinja -DWPE_INCLUDE_DIRS="$HOME/wpe/installed/include/wpe-0.2/" -DWPE_LIBRARIES="$HOME/wpe/installed/lib/libwpe-0.2.so"
ninja
ninja install
```

```
cd $HOME/wpe
wget https://wpewebkit.org/releases/wpewebkit-2.22.4.tar.xz
tar xavf wpewebkit-2.22.4.tar.xz
cd wpewebkit-2.22.4

cmake -DCMAKE_INSTALL_PREFIX=$HOME/wpe/installed/ -DLIB_INSTALL_DIR=$HOME/wpe/installed/lib -DLIBEXEC_INSTALL_DIR=$HOME/wpe/installed/libexec -DEXEC_INSTALL_DIR=$HOME/wpe/installed/bin -DPORT=WPE -DUSE_WOFF2=false -DCMAKE_BUILD_TYPE=RelWithDebInfo -GNinja -DWPE_INCLUDE_DIRS="$HOME/wpe/installed/include/wpe-0.2/" -DWPE_LIBRARIES="$HOME/wpe/installed/lib/libwpe-0.2.so"
ninja # takes a while and requirs quite a bit of RAM (~16GB)
ninja install
```

```
cd $HOME/wpe
git clone https://github.com/MaZderMind/gst-wpesrc.git
cd gst-wpesrc

PKG_CONFIG_PATH=$HOME/wpe/installed/lib/pkgconfig/ ./autogen.sh
make
```

Getting-Started
---------------
```
LD_LIBRARY_PATH"=$HOME/wpe/installed/lib/" ./test-scripts/inspect-wpesrc.sh
LD_LIBRARY_PATH"=$HOME/wpe/installed/lib/" ./test-scripts/run-wpesrc.sh
LD_LIBRARY_PATH"=$HOME/wpe/installed/lib/" ./test-scripts/run-wpesrc-composition.sh
```
