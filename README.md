# RAOP-Player

RAOP player and library (AirPlay)

This is a RAOP (airplay) player and library for the v2 protocol (with synchro). Derived from philippe44/RAOP-Player, this project only works on Linux
There is a small player can can play raw pcm form any file or stdin (useful for use pipes with a decoder like lame, flac or ffmpeg)

The player is just and example how to use the library, but it has a few interesting options:

```text
usage: ./build/raop_play <options> <server_ip> <filename ('-' for stdin)>
	[-ntp <file>] write current NTP in <file> and exit
	[-p <port number>]
	[-v <volume> (0-100)]
	[-l <latency> (frames]
	[-w <wait>]  (start after <wait> milliseconds)
	[-n <start>] (start at NTP <start> + <wait>)
	[-nf <start>] (start at NTP in <file> + <wait>)
	[-e] (encrypt)
	[-s <secret>] (valid secret for AppleTV)
	[-d <debug level>] (0 = silent)
	[-i] (interactive commands: 'p'=pause, 'r'=(re)start, 's'=stop, 'q'=exit, ' '=block)
```

It's possible to send synchronous audio to multiple players by using the NTP options (optionally combined with the wait option).
Either get the NTP of the master machine from any application and then fork multiple instances of raop_play with that NTP and
the same audio file, or use the -ntp option to get NTP to be written to a file and re-use that file when calling the instances of
raop_play

## Building

The project builds using meson and requires the development packages for valgrind and links against openssl

```sh
# install dependencies
sudo dnf install valgrind-devel openssl-libs

# git submodule update --init
meson builddir

# Create build directory
meson builddir
cd builddir

# Build project
meson compile
```

## Extra Info
Since iOS 10.2, pairing is required with AppleTV. Here is a description of the protocol https://htmlpreview.github.io/?https://github.com/philippe44/RAOP-Player/blob/master/doc/auth_protocol.html
