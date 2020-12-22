
  WinPos ウィンドウを指定した位置に移動します

■オプション一覧

  -title TITLE

      TITLE: ウィンドウタイトル

  -rect X1,Y1,X2,Y2

  -style MASK,STYLE

      MASK: ウィンドウスタイルフラグ

  -alpha ALPHA[,COLORKEY]

      ALPHA: 0～255
      COLORKEY: 16進数6桁

■1. ウィンドウ位置を調べる

操作対象のウィンドウを指定するには、-title オプションを使います。
"無題 - メモ帳" というタイトルを持ったウィンドウを指定する場合、以下のようにします。

  >WinPos -title "無題 - メモ帳"
  26,348,1286,844

ウィンドウが見つかれば、ウィンドウ位置が表示されます。
"26,348,1286,844" がウィンドウ位置です。
ウィンドウが見つからない場合は、"ウィンドウが見つかりませんでした" と表示されます。

■2. 位置を設定する

位置を設定するには -rect オプションを使います。

  >WinPos -title "無題 - メモ帳" -rect 10,10,300,300

■3. ウィンドウスタイルを設定する

-style オプションでウィンドウスタイルを変更できます。
ウィンドウのタイトルバーを取り除きたい場合は以下のようにします。

  >WinPos -title "無題 - メモ帳" -style WS_CAPTION,0

再びタイトルバーを復活させたい場合は以下のようにします。

  >WinPos -title "無題 - メモ帳" -style WS_CAPTION,WS_CAPTION

-style MASK,STYLE パラメータは、マスクとスタイルの2つの値を指定します。
C言語的に書けば、以下のようになります。

  NEW_STYLE = STYLE & ~MASK | STYLE;

スタイルは + 記号を使って複数同時に指定できます。
最大化ボタンを無効化し、リサイズ不可能にするには以下のようにします。

  >WinPos -title "無題 - メモ帳" -style WS_MAXIMIZEBOX+WS_THICKFRAME,0

ウィンドウスタイルは、ソフトによって効いたり効かなかったりします。
これは開発者にはしか判別できません。

指定可能なスタイル一覧。
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

■半透明、カラーキー(部分的な透過)

-alpha で不透明度を指定。0で透明、255が不透明。

 >WinPos -title "無題 - メモ帳" -alpha 128
 
-alpha の二つめの数値でカラーキーを指定。ウィンドウ全体を半透明にして、
ffffffの色を完全に透過させる。
(メモ帳の白い部分が完全に透過し、メモ帳のウィンドウ全体は半透明になる)

 >WinPos -title "無題 - メモ帳" -alpha 128,ffffff
 

