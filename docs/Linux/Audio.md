## Audio

### ALSA

**Advanced Linux Sound Architecture (ALSA)** replaced the earlier "Open Sound System". ([src][Schatz])

ALSA kernel modules are designed to offer an interface that "corresponds to that of the hardware" to keep the modules simple, and similar cards will offer a similar interface. They offer two interfaces: **operational** and **configuration**

**Operational interface** through the `/dev/` tree, with 3 main types of devices
- **PCM** for recording or playing digitized sound samples
- **CTL** for manipulating the internal mixer and routing of the card
- **MIDI** to control the MIDI port, if it exists
- Optionally, **sequencer** devices may also exist if the card has a builtin sound synthesizer with an associated **timer** device

**Status and configuration interface** via the `/proc/asound/` tree (ref [`amixer`][amixer])

PCM devices come in two varieties: **output** and **input** and are numbered from 0, which is generally for analog multichannel sound.

Cards have input or output **sockets**, and the **mixer** is controlled by the CTL device and routes sound samples among devices and sockets.

Controls come in 3 types;
- **Playback** controls are associated with an output device or **copy (input-to-output)** routes
- **Capture** controls are associated with an input device or **copy (output-to-input)** routes
- **Feature** controls drive features of the card or mixer, usually just a switch to enable or disable the feature, though some also have levels. The **Master Volume** control is the most typical example, which allows control of the internal amplifier feature of the card. A more interesting example is that of a 3d spatializer that can be represented by a switch to enable or disable it as well as two levels.

Typical channel assignments
- **0**: front left
- **1**: front right
- **2**: rear left
- **3**: rear right

### PulseAudio

PulseAudio is a sound server for POSIX OSes and a fixture on many Linux distributions.

PulseAudio is built around **sources** and **sinks** (i.e. devices) connected to **source outputs** and **sink inputs** (streams)
- **Source** is an input device that produces samples, usually running a thread with its own event loop, generating sample chunks which are posted to all connected source outputs
- **Source output** is a recording stream which consumes samples from a source
- **Sink** is an output device that consumes samples, usually running a thread with its own event loop mixing sample chunks from connect sink inputs
- **Sink input** is a playback stream, connected to a sink and producing samples for it
