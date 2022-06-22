# Arduino UNO

## Requirements

### Packages
Fedora
```bash
dnf install avr-binutils avr-gcc avr-gcc-c++ avr-libc
```

### /dev/

Usually `/dev/ttyACM0`, but need to add the user to dialout `sudo usermod -aG dialout $USER`

## Projects

- [x] port blink to baremetal
- [ ] port LCD to baremetal
