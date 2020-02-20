# Linux commands related to hardware

### `bluetoothctl`
&nbsp;  | `bluetoothctl` commands [<sup>Linux Magazine</sup>][http://www.linux-magazine.com/Issues/2017/197/Command-Line-bluetoothctl#article_i1] [<sup>Computing For Geeks</sup>][https://computingforgeeks.com/connect-to-bluetooth-device-from-linux-terminal/]
---     | ---
A-R     | [`device`][bluetoothctl devices] &bull; [`list`][bluetoothctl list] &bull; [`pair`][bluetoothctl pair] &bull; [`pairable on`][bluetoothctl pairable on]
S       | [`scan on`][bluetoothctl scan on] [`select`][bluetoothctl select] [`show`][bluetoothctl show]

[bluetoothctl devices]:           hw.md#bluetoothctl             '```&#10;$ bluetoothctl&#10;[bluetooth]# devices&#10;```&#10;List available devices'
[bluetoothctl list]:              hw.md#bluetoothctl             '```&#10;$ bluetoothctl&#10;[bluetooth]# list&#10;```&#10;Display available controllers'
[bluetoothctl pair]:              hw.md#bluetoothctl             '```&#10;$ bluetoothctl&#10;[bluetooth]# pair&#10;```&#10;Pair with `$DEVICE`, which is the MAC address of the pairable device'
[bluetoothctl pairable on]:       hw.md#bluetoothctl             '```&#10;$ bluetoothctl&#10;[bluetooth]# pairable on&#10;```&#10;Prepare controller for pairing'
[bluetoothctl scan on]:           hw.md#bluetoothctl             '```&#10;$ bluetoothctl&#10;[bluetooth]# scan on&#10;```&#10;Receive a list of detected devices'
[bluetoothctl select]:            hw.md#bluetoothctl             '```&#10;$ bluetoothctl&#10;[bluetooth]# select&#10;```&#10;Select controller to pair, if the system has more than one'
[bluetoothctl show]:              hw.md#bluetoothctl             '```&#10;$ bluetoothctl&#10;[bluetooth]# show&#10;```&#10;Display more detailed inormation about available controllers'
