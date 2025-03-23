## About Smartmontools

# NOTE: This is an attempt to merge [@mallendeo's smartctl support for USB QNAP TR-004](https://gist.github.com/mallendeo/48dc3d6edbbb40c166dfee987c7ef765) with a modern version of smartmontools since it is built off a 6 year old [Fork by @slade87](https://github.com/slade87/smartmontools) that was never incorporated into the main & is 600 commits behind.
As of now it is not working. I am not familiar with C++ and am mostly using `Grok` to try to figure it out... But it is not working out too well

The smartmontools package contains two utility programs (`smartctl` and `smartd`) 
to control and monitor storage systems using the **Self-Monitoring, Analysis and 
Reporting Technology System** (SMART) built into most modern ATA/SATA, SCSI/SAS and NVMe disks. 
In many cases, these utilities will provide advanced warning of disk degradation and failure.


 
Smartmontools was originally derived from the Linux [smartsuite package](https://sourceforge.net/projects/smartsuite/) and actually supports ATA/SATA,  SCSI/SAS and NVMe disks and also SCSI/SAS tape devices.
It should run on any modern Linux, FreeBSD, NetBSD, OpenBSD, Darwin (macOS), Solaris, Windows, Cygwin, OS/2, eComStation or QNX system.
Smartmontools can also be run from one of many different Live CDs/DVDs.

## Important links

- [Project homepage](https://www.smartmontools.org/)
- [GitHub repository](https://github.com/smartmontools/smartmontools)
- [CI builds](https://builds.smartmontools.org/)
- [Project Releases](https://github.com/smartmontools/smartmontools/releases)


## Code Signing
This program uses free code signing provided by [SignPath.io](https://signpath.io), and a free code signing certificate by the [SignPath Foundation](https://signpath.org)


## License

Smartmontools uses [GNU GPL Version 2](https://www.gnu.org/licenses/gpl-2.0.html#SEC1) license. 
