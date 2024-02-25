
activity:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 82 2f 00 00    	pushq  0x2f82(%rip)        # 3fa8 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 84 2f 00 00    	jmpq   *0x2f84(%rip)        # 3fb0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <puts@plt>:
    1030:	ff 25 82 2f 00 00    	jmpq   *0x2f82(%rip)        # 3fb8 <puts@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	pushq  $0x0
    103b:	e9 e0 ff ff ff       	jmpq   1020 <.plt>

0000000000001040 <gets@plt>:
    1040:	ff 25 7a 2f 00 00    	jmpq   *0x2f7a(%rip)        # 3fc0 <gets@GLIBC_2.2.5>
    1046:	68 01 00 00 00       	pushq  $0x1
    104b:	e9 d0 ff ff ff       	jmpq   1020 <.plt>

0000000000001050 <exit@plt>:
    1050:	ff 25 72 2f 00 00    	jmpq   *0x2f72(%rip)        # 3fc8 <exit@GLIBC_2.2.5>
    1056:	68 02 00 00 00       	pushq  $0x2
    105b:	e9 c0 ff ff ff       	jmpq   1020 <.plt>

0000000000001060 <fwrite@plt>:
    1060:	ff 25 6a 2f 00 00    	jmpq   *0x2f6a(%rip)        # 3fd0 <fwrite@GLIBC_2.2.5>
    1066:	68 03 00 00 00       	pushq  $0x3
    106b:	e9 b0 ff ff ff       	jmpq   1020 <.plt>

Disassembly of section .plt.got:

0000000000001070 <__cxa_finalize@plt>:
    1070:	ff 25 82 2f 00 00    	jmpq   *0x2f82(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1076:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000001080 <_start>:
    1080:	f3 0f 1e fa          	endbr64 
    1084:	31 ed                	xor    %ebp,%ebp
    1086:	49 89 d1             	mov    %rdx,%r9
    1089:	5e                   	pop    %rsi
    108a:	48 89 e2             	mov    %rsp,%rdx
    108d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1091:	50                   	push   %rax
    1092:	54                   	push   %rsp
    1093:	4c 8d 05 a6 02 00 00 	lea    0x2a6(%rip),%r8        # 1340 <__libc_csu_fini>
    109a:	48 8d 0d 2f 02 00 00 	lea    0x22f(%rip),%rcx        # 12d0 <__libc_csu_init>
    10a1:	48 8d 3d a0 01 00 00 	lea    0x1a0(%rip),%rdi        # 1248 <main>
    10a8:	ff 15 32 2f 00 00    	callq  *0x2f32(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    10ae:	f4                   	hlt    
    10af:	90                   	nop

00000000000010b0 <deregister_tm_clones>:
    10b0:	48 8d 3d 61 2f 00 00 	lea    0x2f61(%rip),%rdi        # 4018 <__TMC_END__>
    10b7:	48 8d 05 5a 2f 00 00 	lea    0x2f5a(%rip),%rax        # 4018 <__TMC_END__>
    10be:	48 39 f8             	cmp    %rdi,%rax
    10c1:	74 15                	je     10d8 <deregister_tm_clones+0x28>
    10c3:	48 8b 05 0e 2f 00 00 	mov    0x2f0e(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    10ca:	48 85 c0             	test   %rax,%rax
    10cd:	74 09                	je     10d8 <deregister_tm_clones+0x28>
    10cf:	ff e0                	jmpq   *%rax
    10d1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10d8:	c3                   	retq   
    10d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010e0 <register_tm_clones>:
    10e0:	48 8d 3d 31 2f 00 00 	lea    0x2f31(%rip),%rdi        # 4018 <__TMC_END__>
    10e7:	48 8d 35 2a 2f 00 00 	lea    0x2f2a(%rip),%rsi        # 4018 <__TMC_END__>
    10ee:	48 29 fe             	sub    %rdi,%rsi
    10f1:	48 89 f0             	mov    %rsi,%rax
    10f4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10f8:	48 c1 f8 03          	sar    $0x3,%rax
    10fc:	48 01 c6             	add    %rax,%rsi
    10ff:	48 d1 fe             	sar    %rsi
    1102:	74 14                	je     1118 <register_tm_clones+0x38>
    1104:	48 8b 05 e5 2e 00 00 	mov    0x2ee5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    110b:	48 85 c0             	test   %rax,%rax
    110e:	74 08                	je     1118 <register_tm_clones+0x38>
    1110:	ff e0                	jmpq   *%rax
    1112:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1118:	c3                   	retq   
    1119:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001120 <__do_global_dtors_aux>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	80 3d fd 2e 00 00 00 	cmpb   $0x0,0x2efd(%rip)        # 4028 <completed.8061>
    112b:	75 2b                	jne    1158 <__do_global_dtors_aux+0x38>
    112d:	55                   	push   %rbp
    112e:	48 83 3d c2 2e 00 00 	cmpq   $0x0,0x2ec2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1135:	00 
    1136:	48 89 e5             	mov    %rsp,%rbp
    1139:	74 0c                	je     1147 <__do_global_dtors_aux+0x27>
    113b:	48 8b 3d c6 2e 00 00 	mov    0x2ec6(%rip),%rdi        # 4008 <__dso_handle>
    1142:	e8 29 ff ff ff       	callq  1070 <__cxa_finalize@plt>
    1147:	e8 64 ff ff ff       	callq  10b0 <deregister_tm_clones>
    114c:	c6 05 d5 2e 00 00 01 	movb   $0x1,0x2ed5(%rip)        # 4028 <completed.8061>
    1153:	5d                   	pop    %rbp
    1154:	c3                   	retq   
    1155:	0f 1f 00             	nopl   (%rax)
    1158:	c3                   	retq   
    1159:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001160 <frame_dummy>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	e9 77 ff ff ff       	jmpq   10e0 <register_tm_clones>

0000000000001169 <win>:
    1169:	f3 0f 1e fa          	endbr64 
    116d:	48 83 ec 08          	sub    $0x8,%rsp
    1171:	81 ff 13 52 01 00    	cmp    $0x15213,%edi
    1177:	74 2e                	je     11a7 <win+0x3e>
    1179:	81 ff 13 82 01 00    	cmp    $0x18213,%edi
    117f:	74 34                	je     11b5 <win+0x4c>
    1181:	81 ff 13 86 01 00    	cmp    $0x18613,%edi
    1187:	74 3a                	je     11c3 <win+0x5a>
    1189:	8b 05 a1 2e 00 00    	mov    0x2ea1(%rip),%eax        # 4030 <mystery>
    118f:	3d 13 55 01 00       	cmp    $0x15513,%eax
    1194:	74 3b                	je     11d1 <win+0x68>
    1196:	48 8d 3d d3 0e 00 00 	lea    0xed3(%rip),%rdi        # 2070 <_IO_stdin_used+0x70>
    119d:	e8 8e fe ff ff       	callq  1030 <puts@plt>
    11a2:	48 83 c4 08          	add    $0x8,%rsp
    11a6:	c3                   	retq   
    11a7:	48 8d 3d 5a 0e 00 00 	lea    0xe5a(%rip),%rdi        # 2008 <_IO_stdin_used+0x8>
    11ae:	e8 7d fe ff ff       	callq  1030 <puts@plt>
    11b3:	eb ed                	jmp    11a2 <win+0x39>
    11b5:	48 8d 3d dc 0e 00 00 	lea    0xedc(%rip),%rdi        # 2098 <_IO_stdin_used+0x98>
    11bc:	e8 6f fe ff ff       	callq  1030 <puts@plt>
    11c1:	eb df                	jmp    11a2 <win+0x39>
    11c3:	48 8d 3d 5e 0e 00 00 	lea    0xe5e(%rip),%rdi        # 2028 <_IO_stdin_used+0x28>
    11ca:	e8 61 fe ff ff       	callq  1030 <puts@plt>
    11cf:	eb d1                	jmp    11a2 <win+0x39>
    11d1:	48 8d 3d 78 0e 00 00 	lea    0xe78(%rip),%rdi        # 2050 <_IO_stdin_used+0x50>
    11d8:	e8 53 fe ff ff       	callq  1030 <puts@plt>
    11dd:	eb c3                	jmp    11a2 <win+0x39>

00000000000011df <solve>:
    11df:	f3 0f 1e fa          	endbr64 
    11e3:	48 83 ec 38          	sub    $0x38,%rsp
    11e7:	48 c7 44 24 28 b4 00 	movq   $0xb4,0x28(%rsp)
    11ee:	00 00 
    11f0:	48 c7 44 24 08 af 00 	movq   $0xaf,0x8(%rsp)
    11f7:	00 00 
    11f9:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
    11fe:	e8 76 00 00 00       	callq  1279 <Gets>
    1203:	48 8b 54 24 28       	mov    0x28(%rsp),%rdx
    1208:	48 b8 31 35 32 31 33 	movabs $0x3331323531,%rax
    120f:	00 00 00 
    1212:	48 39 c2             	cmp    %rax,%rdx
    1215:	74 19                	je     1230 <solve+0x51>
    1217:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
    121c:	48 b8 31 38 32 31 33 	movabs $0x3331323831,%rax
    1223:	00 00 00 
    1226:	48 39 c2             	cmp    %rax,%rdx
    1229:	74 11                	je     123c <solve+0x5d>
    122b:	48 83 c4 38          	add    $0x38,%rsp
    122f:	c3                   	retq   
    1230:	bf 13 52 01 00       	mov    $0x15213,%edi
    1235:	e8 2f ff ff ff       	callq  1169 <win>
    123a:	eb db                	jmp    1217 <solve+0x38>
    123c:	bf 13 82 01 00       	mov    $0x18213,%edi
    1241:	e8 23 ff ff ff       	callq  1169 <win>
    1246:	eb e3                	jmp    122b <solve+0x4c>

0000000000001248 <main>:
    1248:	f3 0f 1e fa          	endbr64 
    124c:	48 83 ec 08          	sub    $0x8,%rsp
    1250:	48 8b 35 b9 2d 00 00 	mov    0x2db9(%rip),%rsi        # 4010 <stack_top>
    1257:	48 8d 3d 81 ff ff ff 	lea    -0x7f(%rip),%rdi        # 11df <solve>
    125e:	e8 56 00 00 00       	callq  12b9 <run_on_stack>
    1263:	48 8d 3d 49 0e 00 00 	lea    0xe49(%rip),%rdi        # 20b3 <_IO_stdin_used+0xb3>
    126a:	e8 c1 fd ff ff       	callq  1030 <puts@plt>
    126f:	b8 00 00 00 00       	mov    $0x0,%eax
    1274:	48 83 c4 08          	add    $0x8,%rsp
    1278:	c3                   	retq   

0000000000001279 <Gets>:
    1279:	f3 0f 1e fa          	endbr64 
    127d:	48 83 ec 08          	sub    $0x8,%rsp
    1281:	e8 ba fd ff ff       	callq  1040 <gets@plt>
    1286:	48 85 c0             	test   %rax,%rax
    1289:	74 05                	je     1290 <Gets+0x17>
    128b:	48 83 c4 08          	add    $0x8,%rsp
    128f:	c3                   	retq   
    1290:	48 8b 0d 89 2d 00 00 	mov    0x2d89(%rip),%rcx        # 4020 <stderr@@GLIBC_2.2.5>
    1297:	ba 0d 00 00 00       	mov    $0xd,%edx
    129c:	be 01 00 00 00       	mov    $0x1,%esi
    12a1:	48 8d 3d 28 0e 00 00 	lea    0xe28(%rip),%rdi        # 20d0 <_IO_stdin_used+0xd0>
    12a8:	e8 b3 fd ff ff       	callq  1060 <fwrite@plt>
    12ad:	bf 01 00 00 00       	mov    $0x1,%edi
    12b2:	e8 99 fd ff ff       	callq  1050 <exit@plt>

00000000000012b7 <gadget1>:
    12b7:	5f                   	pop    %rdi
    12b8:	c3                   	retq   

00000000000012b9 <run_on_stack>:
    12b9:	48 89 e2             	mov    %rsp,%rdx
    12bc:	48 8d 66 f8          	lea    -0x8(%rsi),%rsp
    12c0:	52                   	push   %rdx
    12c1:	ff d7                	callq  *%rdi
    12c3:	5a                   	pop    %rdx
    12c4:	48 89 d4             	mov    %rdx,%rsp
    12c7:	c3                   	retq   
    12c8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    12cf:	00 

00000000000012d0 <__libc_csu_init>:
    12d0:	f3 0f 1e fa          	endbr64 
    12d4:	41 57                	push   %r15
    12d6:	4c 8d 3d c3 2a 00 00 	lea    0x2ac3(%rip),%r15        # 3da0 <__frame_dummy_init_array_entry>
    12dd:	41 56                	push   %r14
    12df:	49 89 d6             	mov    %rdx,%r14
    12e2:	41 55                	push   %r13
    12e4:	49 89 f5             	mov    %rsi,%r13
    12e7:	41 54                	push   %r12
    12e9:	41 89 fc             	mov    %edi,%r12d
    12ec:	55                   	push   %rbp
    12ed:	48 8d 2d b4 2a 00 00 	lea    0x2ab4(%rip),%rbp        # 3da8 <__do_global_dtors_aux_fini_array_entry>
    12f4:	53                   	push   %rbx
    12f5:	4c 29 fd             	sub    %r15,%rbp
    12f8:	48 83 ec 08          	sub    $0x8,%rsp
    12fc:	e8 ff fc ff ff       	callq  1000 <_init>
    1301:	48 c1 fd 03          	sar    $0x3,%rbp
    1305:	74 1f                	je     1326 <__libc_csu_init+0x56>
    1307:	31 db                	xor    %ebx,%ebx
    1309:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1310:	4c 89 f2             	mov    %r14,%rdx
    1313:	4c 89 ee             	mov    %r13,%rsi
    1316:	44 89 e7             	mov    %r12d,%edi
    1319:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    131d:	48 83 c3 01          	add    $0x1,%rbx
    1321:	48 39 dd             	cmp    %rbx,%rbp
    1324:	75 ea                	jne    1310 <__libc_csu_init+0x40>
    1326:	48 83 c4 08          	add    $0x8,%rsp
    132a:	5b                   	pop    %rbx
    132b:	5d                   	pop    %rbp
    132c:	41 5c                	pop    %r12
    132e:	41 5d                	pop    %r13
    1330:	41 5e                	pop    %r14
    1332:	41 5f                	pop    %r15
    1334:	c3                   	retq   
    1335:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    133c:	00 00 00 00 

0000000000001340 <__libc_csu_fini>:
    1340:	f3 0f 1e fa          	endbr64 
    1344:	c3                   	retq   

Disassembly of section .fini:

0000000000001348 <_fini>:
    1348:	f3 0f 1e fa          	endbr64 
    134c:	48 83 ec 08          	sub    $0x8,%rsp
    1350:	48 83 c4 08          	add    $0x8,%rsp
    1354:	c3                   	retq   
