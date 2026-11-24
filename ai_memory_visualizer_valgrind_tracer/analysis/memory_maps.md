# Memory Maps and Lifetime Analysis (`stack_example` & `aliasing_example`)

## 1. `stack_example`: Stack Frames & Automatic Lifetimes

### Observed Execution Output
```text
stack_example: recursion and stack frames
  depth=0  &marker=0x7ffcf582eb84  marker=0
    &local_int=0x7ffcf582eb34  p_local=0x7ffcf582eb34  local_int=100
    local_buf=0x7ffcf582eb40  local_buf[0]=A
  depth=1  &marker=0x7ffcf582eb54  marker=10
    &local_int=0x7ffcf582eb04  p_local=0x7ffcf582eb04  local_int=101
    local_buf=0x7ffcf582eb10  local_buf[0]=B
  depth=2  &marker=0x7ffcf582eb24  marker=20
    ...
  [exit] depth=1
    &local_int=0x7ffcf582eb04  p_local=0x7ffcf582eb04  local_int=101
    local_buf=0x7ffcf582eb10  local_buf[0]=B
    &marker=0x7ffcf582eb54  marker=10
  [exit] depth=0
    &local_int=0x7ffcf582eb34  p_local=0x7ffcf582eb34  local_int=100
    local_buf=0x7ffcf582eb40  local_buf[0]=A
    &marker=0x7ffcf582eb84  marker=0