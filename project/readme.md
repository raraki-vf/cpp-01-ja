# Drive Adventure!

1. ゲームを始めるには
   1. ターミナルを開き、以下を実行して下さい
    `g++ -std=c++17 -o main main.cpp`
   2. 次に以下を実行してください
    `./main`

2. ゲームの遊び方
   1. ゲームが始まると地図が表示され、地図上にはプレーヤーの車`C`と、ランドマーク`g, S`、ゴール`G`が現れます。
   2. 停止、左折、右折、加速、減速の5つどれかのコマンドを入力し、Enterを押すとプレーヤーの車`C`が移動します。
   3. コマンドを組み合わせて`C`をゴール`G`まで移動させればゲームクリアです。
        ※地図の外に出ることはできません

3. プロジェクトにおける重要な設計やその設計理由
   * 地図上における自車位置の管理
     * 変えてはいけないランドマークと、移動するため変える必要がある自車位置の情報を切り分けて管理しなければならない