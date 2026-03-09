*This project has been created as part of the 42 curriculum by __ssharmaz__*.

# Description

The project's goal is to learn about sorting algorithms and complexity.
The program should take some random integers without duplicates as an input, save it into the stack A, and output instructions to sort the stack using additional stack B and commands:
- sa (swap a): Swap the first 2 elements at the top of stack a.
- sb (swap b): Swap the first 2 elements at the top of stack b.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
- pb (push b): Take the first element at the top of a and put it at the top of b.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

# Instructions

make
./

## Some useful commands

### Check a file hashsum on Linux
```
sha1sum Born2beroot.vdi
```

### Service management
```
/usr/sbin/service sshd status
```

### User management
`id`, `useradd`, `usermod`, `groups`, `passwd`

### To manage firewall
```bash
sudo ufw allow 4242/tcp
sudo ufw enable
sudo ufw status
```

### How to load CPU
```
for i in 1 2 3 4; do while : ; do : ; done & done
```

## Monitoring script
```bash
#!/usr/bin/env bash

LVM_USAGE=$(lsblk | grep -q lvm && echo yes || echo no)
CPU_USAGE=$(vmstat 1 2 | awk 'END{print 100-$15}')
MAC_ADDR=$(ip link show | awk '/link\/ether/ {print $2}')
IP_ADDR=$(hostname -I)

echo "#Architecture: $(uname -a)"
echo "#CPU physical: $(lscpu | grep Socket | awk '{print $2}')"
echo "#vCPU: $(nproc)"
free -m | awk 'NR==2{avail=$7; used=$3; total=$2; printf "#Memory usage: %d/%dMB (%.2f%%). Available: %dMB\n", used, total, used*100/total, avail}'
df -h --total | awk 'END{printf "#Disk Usage: %s/%s (%s). Available: %s\n", $3, $2, $5, $4}'
echo "#CPU Usage: $CPU_USAGE%"
echo "#Last boot: $(uptime -s)"
echo "#LVM use: $LVM_USAGE"
echo "#Established TCP connections: $(ss -ta | grep ESTAB | wc -l)"
echo "#Users: $(who | awk '{print $1}' | sort -u | wc -l)"
echo "#Network: $IP_ADDR ($MAC_ADDR)"
echo "#Sudo: $(journalctl _COMM=sudo | grep "COMMAND=" | wc -l)"
```

## Password policy configuration

```
/etc/login.defs
/etc/security/pwquality.conf
/etc/pam.d/common-password
```

# Resources
## Bash cheatsheet
https://devhints.io/bash

## Journalctl usage in Debian
https://www.hostinger.com/tutorials/journalctl-command


https://man7.org/linux/man-pages/man1/journalctl.1.html


https://man7.org/linux/man-pages/man7/systemd.journal-fields.7.html


# Debian vs Rocky Linux

Debian is better if you are using Ubuntu regularily. It has huge package ecosystem, and very common for servers and desktops.
A stable release typically gets ~5 years of support (3 years + 2 years LTS).

Rocky Linux: RHEL-compatible OS with a ~10-year lifecycle. OS is creating by community from RHEL sources.

## Main differences
### Packages
Debian is using apt/dpkg; Rocky is using dnf/rpm.

### Applications
Rocky tends to match enterprise defaults (SELinux, firewalld); Debian is usually has newer versions of applications. Debian is using AppArmor by default.


# AppArmor vs SELinux
Both systems created to enforce politics to installed software.

AppArmor: path-based rules. It's profiles describe what a program can do based on file paths.

SELinux is a label/context-based mandatory access control system.
Every process/resource gets labels; adnd policy decides what interactions are allowed.


# UFW vs firewalld

UFW is a simple host firewall CLI. It's a frontend for iptables/netfilter, designed to be easy.

firewalld is a dynamic firewall manager with zones and services.


With firewalld, you can make changes that take effect immediately without committing them permanently.

With UFW, you typically just use “allow/deny” rules for the machine.


# VirtualBox vs UTM

Both are hypervisors: software to emulate handware to run another OS.

VirtualBox is cross-platform hypervisor for Windows/macOS/Linux hosts.

UTM is macOS/iOS-focused hypervisor built on QEMU.
