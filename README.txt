
  WinPos �E�B���h�E���w�肵���ʒu�Ɉړ����܂�

���I�v�V�����ꗗ

  -title TITLE

      TITLE: �E�B���h�E�^�C�g��

  -rect X1,Y1,X2,Y2

  -style MASK,STYLE

      MASK: �E�B���h�E�X�^�C���t���O

  -alpha ALPHA[,COLORKEY]

      ALPHA: 0�`255
      COLORKEY: 16�i��6��

��1. �E�B���h�E�ʒu�𒲂ׂ�

����Ώۂ̃E�B���h�E���w�肷��ɂ́A-title �I�v�V�������g���܂��B
"���� - ������" �Ƃ����^�C�g�����������E�B���h�E���w�肷��ꍇ�A�ȉ��̂悤�ɂ��܂��B

  >WinPos -title "���� - ������"
  26,348,1286,844

�E�B���h�E��������΁A�E�B���h�E�ʒu���\������܂��B
"26,348,1286,844" ���E�B���h�E�ʒu�ł��B
�E�B���h�E��������Ȃ��ꍇ�́A"�E�B���h�E��������܂���ł���" �ƕ\������܂��B

��2. �ʒu��ݒ肷��

�ʒu��ݒ肷��ɂ� -rect �I�v�V�������g���܂��B

  >WinPos -title "���� - ������" -rect 10,10,300,300

��3. �E�B���h�E�X�^�C����ݒ肷��

-style �I�v�V�����ŃE�B���h�E�X�^�C����ύX�ł��܂��B
�E�B���h�E�̃^�C�g���o�[����菜�������ꍇ�͈ȉ��̂悤�ɂ��܂��B

  >WinPos -title "���� - ������" -style WS_CAPTION,0

�Ăу^�C�g���o�[�𕜊����������ꍇ�͈ȉ��̂悤�ɂ��܂��B

  >WinPos -title "���� - ������" -style WS_CAPTION,WS_CAPTION

-style MASK,STYLE �p�����[�^�́A�}�X�N�ƃX�^�C����2�̒l���w�肵�܂��B
C����I�ɏ����΁A�ȉ��̂悤�ɂȂ�܂��B

  NEW_STYLE = STYLE & ~MASK | STYLE;

�X�^�C���� + �L�����g���ĕ��������Ɏw��ł��܂��B
�ő剻�{�^���𖳌������A���T�C�Y�s�\�ɂ���ɂ͈ȉ��̂悤�ɂ��܂��B

  >WinPos -title "���� - ������" -style WS_MAXIMIZEBOX+WS_THICKFRAME,0

�E�B���h�E�X�^�C���́A�\�t�g�ɂ���Č�����������Ȃ������肵�܂��B
����͊J���҂ɂ͂������ʂł��܂���B

�w��\�ȃX�^�C���ꗗ�B
  WS_OVERLAPPED
  WS_POPUP
  WS_CHILD
  WS_MINIMIZE
  WS_VISIBLE
  WS_DISABLED
  WS_CLIPSIBLINGS
  WS_CLIPCHILDREN
  WS_MAXIMIZE
  WS_CAPTION
  WS_BORDER
  WS_DLGFRAME
  WS_VSCROLL
  WS_HSCROLL
  WS_SYSMENU
  WS_THICKFRAME
  WS_GROUP
  WS_TABSTOP
  WS_MINIMIZEBOX
  WS_MAXIMIZEBOX

���������A�J���[�L�[(�����I�ȓ���)

-alpha �ŕs�����x���w��B0�œ����A255���s�����B

 >WinPos -title "���� - ������" -alpha 128
 
-alpha �̓�߂̐��l�ŃJ���[�L�[���w��B�E�B���h�E�S�̂𔼓����ɂ��āA
ffffff�̐F�����S�ɓ��߂�����B
(�������̔������������S�ɓ��߂��A�������̃E�B���h�E�S�͔̂������ɂȂ�)

 >WinPos -title "���� - ������" -alpha 128,ffffff
 

