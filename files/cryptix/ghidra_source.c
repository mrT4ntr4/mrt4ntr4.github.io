
void * Does_Something(long lParm1,int iParm2)

{
  void *pvVar1;
  long in_FS_OFFSET;
  uint local_84;
  int local_80;
  int local_7c;
  uint local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_58 = 0x4847464544434241;
  local_50 = 0x504f4e4d4c4b4a49;
  local_48 = 0x5857565554535251;
  local_40 = 0x6665646362615a59;
  local_38 = 0x6e6d6c6b6a696867;
  local_30 = 0x767574737271706f;
  local_28 = 0x333231307a797877;
  local_20 = 0x2f2b393837363534;
  local_18 = 0;
  pvVar1 = malloc(1000);
  local_7c = 0;
  local_68 = 0;
  local_70 = 0;
  while (local_70 < iParm2) {
    local_78 = 0;
    local_74 = 0;
    local_6c = local_70;
    while ((local_6c < iParm2 && (local_6c <= local_70 + 2))) {
      local_78 = local_78 << 8 | (int)*(char *)(lParm1 + (long)local_6c);
      local_74 = local_74 + 1;
      local_6c = local_6c + 1;
    }
    local_80 = local_74 * 8;
    local_7c = local_80 % 3;
    while (local_80 != 0) {
      if (local_80 < 6) {
        local_84 = local_78 << (6U - (char)local_80 & 0x1f);
        local_80 = 0;
      }
      else {
        local_84 = (int)local_78 >> ((char)local_80 - 6U & 0x1f);
        local_80 = local_80 + -6;
      }
      local_84 = local_84 & 0x3f;
      *(undefined *)((long)local_68 + (long)pvVar1) =
           *(undefined *)((long)&local_58 + (long)(int)local_84);
      local_68 = local_68 + 1;
    }
    local_70 = local_70 + 3;
  }
  local_70 = 1;
  while (local_70 <= local_7c) {
    *(undefined *)((long)pvVar1 + (long)local_68) = 0x3d;
    local_70 = local_70 + 1;
    local_68 = local_68 + 1;
  }
  *(undefined *)((long)pvVar1 + (long)local_68) = 0;
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pvVar1;
}


undefined8 validate_key(char *pcParm1)

{
  size_t sVar1;
  undefined8 uVar2;
  long lVar3;
  double dVar4;
  int local_20;
  
  sVar1 = strlen(pcParm1);
  if ((int)sVar1 == 0x11) {
    lVar3 = Does_Something(pcParm1,0x11);
    local_20 = 0;
    while (local_20 < 0x18) {
      dVar4 = pow(2.00000000,(double)(int)*(char *)(lVar3 + (long)local_20));
      if (*(double *)(_Zproc_libc_fini + (long)local_20 * 8) != dVar4) {
        puts("Sorry no flag for you");
        return 0;
      }
      local_20 = local_20 + 1;
    }
    uVar2 = 1;
  }
  else {
    puts("Sorry no flag for you");
    uVar2 = 0;
  }
  return uVar2;
}


undefined8 main(int iParm1,long lParm2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (iParm1 < 2) {
    puts("Usage: ./keygen <KEY>");
    uVar2 = 1;
  }
  else {
    iVar1 = validate_key(*(undefined8 *)(lParm2 + 8));
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      printf("Congratulations!! here is you flag: flag{%s}",*(undefined8 *)(lParm2 + 8));
      uVar2 = 1;
    }
  }
  return uVar2;
}

