#include "cmd-io/cmd-menu-content-table.h"
#include "util/int-char-converter.h"

special_menu_content special_menu_info[MAX_SPECIAL_MENU_NUM] = {
    { _("超能力/特殊能力", "MindCraft/Special"), 0, 0, MENU_CLASS, CLASS_MINDCRAFTER },
    { _("ものまね/特殊能力", "Imitation/Special"), 0, 0, MENU_CLASS, CLASS_IMITATOR },
    { _("歌/特殊能力", "Song/Special"), 0, 0, MENU_CLASS, CLASS_BARD },
    { _("必殺技/特殊能力", "Technique/Special"), 0, 0, MENU_CLASS, CLASS_SAMURAI },
    { _("練気術/魔法/特殊能力", "Mind/Magic/Special"), 0, 0, MENU_CLASS, CLASS_FORCETRAINER },
    { _("技/特殊能力", "BrutalPower/Special"), 0, 0, MENU_CLASS, CLASS_BERSERKER },
    { _("技術/特殊能力", "Technique/Special"), 0, 0, MENU_CLASS, CLASS_SMITH },
    { _("鏡魔法/特殊能力", "MirrorMagic/Special"), 0, 0, MENU_CLASS, CLASS_MIRROR_MASTER },
    { _("忍術/特殊能力", "Ninjutsu/Special"), 0, 0, MENU_CLASS, CLASS_NINJA },
    { _("広域マップ(<)", "Enter global map(<)"), 2, 6, MENU_WILD, FALSE },
    { _("通常マップ(>)", "Enter local map(>)"), 2, 7, MENU_WILD, TRUE },
    { "", 0, 0, 0, 0 },
};

menu_content menu_info[MAX_COMMAND_MENU_NUM][MAX_COMMAND_PER_SCREEN] = {
    {
        { _("魔法/特殊能力", "Magic/Special"), 1, FALSE },
        { _("行動", "Action"), 2, FALSE },
        { _("道具(使用)", "Items(use)"), 3, FALSE },
        { _("道具(その他)", "Items(other)"), 4, FALSE },
        { _("装備", "Equip"), 5, FALSE },
        { _("扉/箱", "Door/Box"), 6, FALSE },
        { _("情報", "Information"), 7, FALSE },
        { _("設定", "Options"), 8, FALSE },
        { _("その他", "Other commands"), 9, FALSE },
        { "", 0, FALSE },
    },

    { { _("使う(m)", "Use(m)"), 'm', TRUE },
        { _("調べる(b/P)", "See tips(b/P)"), 'b', TRUE },
        { _("覚える(G)", "Study(G)"), 'G', TRUE },
        { _("特殊能力を使う(U/O)", "Special abilities(U/O)"), 'U', TRUE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE } },

    { { _("休息する(R)", "Rest(R)"), 'R', TRUE },
        { _("トラップ解除(D)", "Disarm a trap(D)"), 'D', TRUE },
        { _("探す(s)", "Search(s)"), 's', TRUE },
        { _("周りを調べる(l/x)", "Look(l/x)"), 'l', TRUE },
        { _("ターゲット指定(*)", "Target(*)"), '*', TRUE },
        { _("穴を掘る(T/^t)", "Dig(T/^t)"), 'T', TRUE },
        { _("階段を上る(<)", "Go up stairs(<)"), '<', TRUE },
        { _("階段を下りる(>)", "Go down stairs(>)"), '>', TRUE },
        { _("ペットに命令する(p)", "Command pets(p)"), 'p', TRUE },
        { _("探索モードのON/OFF(S/#)", "Search mode ON/OFF(S/#)"), 'S', TRUE } },

    { { _("読む(r)", "Read a scroll(r)"), 'r', TRUE },
        { _("飲む(q)", "Drink a potion(q)"), 'q', TRUE },
        { _("杖を使う(u/Z)", "Use a staff(u/Z)"), 'u', TRUE },
        { _("魔法棒で狙う(a/z)", "Aim a wand(a/z)"), 'a', TRUE },
        { _("ロッドを振る(z/a)", "Zap a rod(z/a)"), 'z', TRUE },
        { _("始動する(A)", "Activate equipped item(A)"), 'A', TRUE },
        { _("食べる(E)", "Eat(E)"), 'E', TRUE },
        { _("飛び道具で撃つ(f/t)", "Fire missile weapon(f/t)"), 'f', TRUE },
        { _("投げる(v)", "Throw an item(v)"), 'v', TRUE },
        { "", 0, FALSE } },

    { { _("拾う(g)", "Get items(g)"), 'g', TRUE },
        { _("落とす(d)", "Drop an item(d)"), 'd', TRUE },
        { _("壊す(k/^d)", "Destroy an item(k/^d)"), 'k', TRUE },
        { _("銘を刻む({)", "Inscribe an item({)"), '{', TRUE },
        { _("銘を消す(})", "Uninscribe an item(})"), '}', TRUE },
        { _("調査(I)", "Uninscribe an item(})"), 'I', TRUE },
        { _("アイテム一覧(i)", "Inventory list(i)"), 'i', TRUE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE } },

    { { _("装備する(w)", "Wear(w)"), 'w', TRUE },
        { _("装備を外す(t/T)", "Take off(t/T)"), 't', TRUE },
        { _("燃料を補給(F)", "Refuel(F)"), 'F', TRUE },
        { _("装備一覧(e)", "Equipment list(e)"), 'e', TRUE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE } },

    { { _("開ける(o)", "Open(o)"), 'o', TRUE },
        { _("閉じる(c)", "Close(c)"), 'c', TRUE },
        { _("体当たりする(B/f)", "Bash a door(B/f)"), 'B', TRUE },
        { _("くさびを打つ(j/S)", "Jam a door(j/S)"), 'j', TRUE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE } },

    { { _("ダンジョンの全体図(M)", "Full map(M)"), 'M', TRUE },
        { _("位置を確認(L/W)", "Map(L/W)"), 'L', TRUE },
        { _("階の雰囲気(^f)", "Level feeling(^f)"), KTRL('F'), TRUE },
        { _("ステータス(C)", "Character status(C)"), 'C', TRUE },
        { _("文字の説明(/)", "Identify symbol(/)"), '/', TRUE },
        { _("メッセージ履歴(^p)", "Show prev messages(^p)"), KTRL('P'), TRUE },
        { _("現在の時刻(^t/')", "Current time(^t/')"), KTRL('T'), TRUE },
        { _("現在の知識(~)", "Various information(~)"), '~', TRUE },
        { _("プレイ記録(|)", "Play record menu(|)"), '|', TRUE },
        { "", 0, FALSE } },

    { { _("オプション(=)", "Set options(=)"), '=', TRUE },
        { _("マクロ(@)", "Interact with macros(@)"), '@', TRUE },
        { _("画面表示(%)", "Interact w/ visuals(%)"), '%', TRUE },
        { _("カラー(&)", "Interact with colors(&)"), '&', TRUE },
        { _("設定変更コマンド(\")", "Enter a user pref(\")"), '\"', TRUE },
        { _("自動拾いをロード($)", "Reload auto-pick pref($)"), '$', TRUE },
        { _("システム(!)", "System(!)"), '!', TRUE },
        { "", 0, FALSE },
        { "", 0, FALSE },
        { "", 0, FALSE } },

    { { _("セーブ&中断(^x)", "Save and quit(^x)"), KTRL('X'), TRUE },
        { _("セーブ(^s)", "Save(^s)"), KTRL('S'), TRUE },
        { _("ヘルプ(?)", "Help(out-of-date)(?)"), '?', TRUE },
        { _("再描画(^r)", "Redraw(^r)"), KTRL('R'), TRUE },
        { _("メモ(:)", "Take note(:)"), ':', TRUE },
        { _("記念撮影())", "Dump screen dump(()"), ')', TRUE },
        { _("記念撮影の表示(()", "Load screen dump())"), '(', TRUE },
        { _("バージョン情報(V)", "Version info(V)"), 'V', TRUE },
        { _("引退する(Q)", "Quit(Q)"), 'Q', TRUE },
        { "", 0, FALSE } },
};
