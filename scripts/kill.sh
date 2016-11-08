#!/bin/bash
umount /coda
killall lt-venus
rm -rf /var/lib/coda/cache/00
#cfs fl /coda/test...

