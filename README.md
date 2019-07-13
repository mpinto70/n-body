# Multiparticle gravity system

Inspired by https://wordpress.com/read/blogs/158040751/posts/26

## How to get solar system information
According to https://www.physicsforums.com/threads/current-velocities-of-planets.114165/.

Send and email to horizons@ssd.jpl.nasa.gov with subject **job** and content

```
!$$SOF
EMAIL_ADDR = ''
START_TIME = '2006-Mar-13 17:30:58'
STOP_TIME = '2006-Mar-13 17:30:59'
TABLE_TYPE = 'Vector'
REF_PLANE = 'Ecliptic'
CENTER = '@010'
COMMAND = '199'
!$$EOF
```

| Planet  | Command | Position (col) | Velocity (col) |
| ------- | ------: | :------------: | :------------: |
| Sun     |     010 | 2 3 4          | 5 6 7          |
| Mercury |     199 | 8 9 10         | 11 12 13       |
| Venus   |     299 | 14 15 16       | 17 18 19       |
| Earth   |     399 | 20 21 22       | 23 24 25       |
| Mars    |     499 | 26 27 28       | 29 30 31       |
| Jupiter |     599 | 32 33 34       | 35 36 37       |
| Saturn  |     699 | 38 39 40       | 41 42 43       |
| Uranus  |     799 | 44 45 46       | 47 48 49       |
| Neptune |     899 | 50 51 52       | 53 54 55       |
| Pluto   |     999 | 56 57 58       | 59 60 61       |
| Charon  |     901 | 62 63 64       | 65 66 67       |
