```
To tail the journal:

sudo journalctl -f
To list journal entries for the elasticsearch service:

sudo journalctl --unit elasticsearch
To list journal entries for the elasticsearch service starting from a given time:

sudo journalctl --unit elasticsearch --since  "2016-10-30 18:17:16"
```
Check man journalctl or https://www.freedesktop.org/software/systemd/man/journalctl.html for more command line options.  
