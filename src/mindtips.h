#ifdef JP
static char *mind_tips[5][MAX_MIND_POWERS] =
{
{
	"近くの全ての見えるモンスターを感知する。レベル5で罠/扉、15で透明なモンスター、30で財宝とアイテムを感知できるようになる。レベル20で周辺の地形を感知し、45でその階全体を永久に照らし、ダンジョン内のすべてのアイテムを感知する。レベル25で一定時間テレパシーを得る。",
	"精神攻撃のビームまたは球を放つ。",
	"近距離のテレポートをする。",
	"遠距離のテレポートをする。",
	"レベル30未満で、モンスターを朦朧か混乱か恐怖させる球を放つ。レベル30以上で視界内の全てのモンスターを魅了する。抵抗されると無効。",
	"テレキネシスの球を放つ。",
	"一定時間、ACを上昇させる。レベルが上がると、酸、炎、冷気、電撃、毒の耐性も得られる。",
	"レベル25未満で、アイテムの雰囲気を知る。レベル25以上で、アイテムを鑑定する。",
	"レベル25未満で、自分を中心とした精神攻撃の球を発生させる。レベル25以上で、視界内の全てのモンスターに対して精神攻撃を行う。",
	"恐怖と朦朧から回復し、ヒーロ気分かつ加速状態でなければHPが少し回復する。さらに、一定時間ヒーロー気分になり、加速する。",
	"アイテムを自分の足元へ移動させる。",
	"精神攻撃の球を放つ。モンスターに命中すると、0〜1.5ターン消費する。抵抗されなければ、MPが回復する。",
	"無傷球をも切り裂く純粋なエネルギーのビームを放つ。",
	"時を止める。全MPを消費し、消費したMPに応じて長く時を止めていられる。",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
},
{
	"ごく小さい気の球を放つ。",
	"光源が照らしている範囲か部屋全体を永久に明るくする。",
	"一定時間、空中に浮けるようになる。",
	"射程の短い気のビームを放つ。",
	"一定時間、魔法防御能力を上昇させる。",
	"気を練る。気を練ると術の威力は上がり、持続時間は長くなる。練った気は時間とともに拡散する。練りすぎると暴走する危険がある。",
	"一定時間、攻撃してきた全てのモンスターを傷つけるオーラを纏う。",
	"隣りのモンスターに対して気をぶつけ、吹きとばす。",
	"大きな気の球を放つ。",
	"モンスター1体にかかった魔法を解除する。",
	"1体の幽霊を召喚する。",
	"自分を中心とした超巨大な炎の球を発生させる。",
	"射程の長い、強力な気のビームを放つ。",
	"しばらくの間、非常に速く動くことができる。",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
},
{
	"近くの思考することができるモンスターを感知する。",
	"攻撃した後、反対側に抜ける。",
	"トラップにかかるが、そのトラップを破壊する。",
	"周囲のダンジョンを揺らし、壁と床をランダムに入れ変える。",
	"全方向に向かって攻撃する。",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
},
{
	"近くの全てのモンスターを感知する。レベル15で透明なモンスターを感知する。レベル25で一定時間テレパシーを得る。レベル35で周辺の地形を感知する。全ての効果は、鏡の上でないとレベル4だけ余計に必要になる。",
	"自分のいる床の上に鏡を生成する",
	"閃光の矢を放つ。レベル10以上では鏡の上で使うとビームになる。",
	"近距離のテレポートをする。",
	"自分の周囲や、 自分のいる部屋全体を明るくする。",
	"遠距離のテレポートをする。",
	"一定時間、鏡のオーラが付く。攻撃を受けると破片のダメージで反撃し、さらに鏡の上にいた場合近距離のテレポートをする。",
	"モンスターを1体テレポートさせる。",
	"破片の球を放つ。",
	"全ての鏡の周りに眠りの球を発生させる。",
	"ターゲットに向かって魔力のビームを放つ。鏡に命中すると、その鏡を破壊し、別の鏡に向かって反射する。",
	"鏡の上のモンスターを消し去る。",
	"一定時間、ACを上昇させる。レベル32で反射が付く。レベル40で魔法防御が上がる。",
	"ターゲットに向かって強力な魔力のビームを放つ。鏡に命中すると、その鏡を破壊し、8方向に魔力のビームを発生させる。",
	"視界内のモンスターを減速させ、朦朧とさせ、混乱させ、恐怖させ、麻痺させる。鏡の上で使うと威力が高い。",
	"フロアを作り変える。鏡の上でしか使えない。",
	"短距離内の指定した場所にテレポートする。",
	"地上にいるときはダンジョンの最深階へ、ダンジョンにいるときは地上へと移動する。",
	"全ての攻撃が、1/2の確率で無効になる。",
	"視界内の2つの鏡とプレイヤーを頂点とする三角形の領域に、魔力の結界を発生させる。",
	"一定時間、ダメージを受けなくなるバリアを張る。切れた瞬間に少しターンを消費するので注意。",
},
{
	"半径3以内かその部屋を暗くする。",
	"近くの全ての見えるモンスターを感知する。レベル5で罠/扉/階段、レベル15でアイテムを感知できるようになる。レベル45でその階全体の地形と全てのアイテムを感知する。",
	"近距離のテレポートをする。",
	"攻撃を受けた瞬間にテレポートをするようになる。失敗するとその攻撃のダメージを受ける。テレポートに失敗することもある。",
	"遠距離のテレポートをする。",
	"攻撃してすぐにテレポートする。",
	"敵1体の動きを封じる。ユニークモンスター相手の場合又は抵抗された場合には無効。",
	"アイテムを識別する。",
	"一定時間、浮遊能力を得る。",
	"自分を中心とした火の球を発生させ、テレポートする。さらに、一定時間炎に対する耐性を得る。装備による耐性に累積する。",
	"素早く相手に近寄り攻撃する。",
	"ランダムな方向に8回くさびを投げる。",
	"敵を1体自分の近くに引き寄せる。",
	"ダメージのない混乱の球を放つ。",
	"1体のモンスターと位置を交換する。",
	"自分のいる床の上に、モンスターが通ると爆発してダメージを与えるルーンを描く。",
	"一定時間、半物質化し壁を通り抜けられるようになる。さらに、一定時間酸への耐性を得る。装備による耐性に累積する。",
	"自分を中心とした超巨大な毒、生命力吸収、混乱の球を発生させ、テレポートする。",
	"ランダムな方向に何回か炎か地獄かプラズマのビームを放つ。",
	"全ての攻撃が、1/2の確率で無効になる。",
	"",
},
};
#else
static char *mind_tips[5][MAX_MIND_POWERS] =
{
{
	"detects visible monsters in the neighborhood and more and more. detects traps and doors at level 5, invisible monsters at level 15, items at level 30. And magic mapping at level 20. lights and know the whole level at level 45. gives telepathy at level 25",
	"fires a beam or ball which inflicts PSI damage.",
	"teleport short distance.",
	"teleport long distance.",
	"stuns, confuses or scares a monster. or attempts to charm all monsters in sight at level 30.",
	"fires a ball which hurts monsters with telekinesis",
	"gives stone skin and some resistance to elements for a while. The level increased, the more number of resistances given.",
	"gives feeling of an item. or identify an item at level 25.",
	"generate a ball centered on you which inflict monster with PSI damage. or inflict all monsters with PSI damage at level 25",
	"removes fear and stun. gives hiroism and speed. heals HP a little unless you already have hiroism and temporal speed boost.",
	"pulls a distant item close to you.",
	"fires a ball which damages monsters and absorbs monsters' mind power. absorbing is takes more turns which from 0 to 1.5.",
	"fires a beam of pure energy which penetrate the invulnerability barrier.",
	"stops time. consumes all of your SP. The more consumes SP, the longer duration of spell.",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
},
{
	"fires a very small energy ball.",
	"lights up nearby area and the inside of a room permanently.",
	"gives levitaion a while.",
	"fires a short energy beam.",
	"gives magic resistance for a while.",
	"improves spirit energy power temporaly. Improved spirit energy will be more and more powerfull or have longer duration. Too many improving results in uncontrollable explosion of spirit energy.",
	"gives aura which damages all monsters which attacked you for a while.",
	"damages an adjacent monster, and blow it away.",
	"fires a large energy ball.",
	"dispels all magics which is effecting a monster.",
	"summons ghosts.",
	"generates a huge ball of frame which centered on you.",
	"fires a long, powerful energy beam.",
	"gives extremely fast speed.",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
},
{
	"detects all monsters except mindless in the neighborhood.",
	"attacks monster with your weapons normaly, then move through counter side of the monster.",
	"sets off a trap, then destroy that trap.",
	"shakes dungeon structure, and results in random swaping of floors and walls.",
	"attacks all adjacent monsters.",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
},
{
	"detects visible monsters in the neighborhood and more and more. detects invisible monsters at level 15. gives telepathy at level 25. Magic mapping at level 35. All of effects need 4 more levels unless on a mirror.",
	"makes a mirror under you.",
	"fires bolt of flash light. or fires beam of light on a mirror at level 10",
	"teleport short distance.",
	"lights up nearby area and the inside of a room permanently.",
	"teleport long distance.",
	"gives aura of shards of mirror for a while. It couse counter attack to monsters which attacks you.",
	"attempts to teleport a monster away.",
	"fires a ball of shards",
	"generate balls which send monsters to sleep on all mirrors in the whole level.",
	"fires a beam of mana. If the beam hit a mirror, it breaks that mirror and reflects toward another mirror.",
	"vanich a monster on a mirror from current dungeon level.",
	"gives bonus to AC. gives reflection at level 32. gives magic resistance at level 40.",
	"fires a powerful beam of mana. If the beam hit a mirror, it breaks that mirror and fires 8 beams of mana to 8 differnt directions from that point.",
	"attempts to slow, stun, confuse, scare, freeze all monsters in sight. gets more power on a mirror.",
	"recreates current dungeon level. can only be used on a mirror.",
	"teleport to given location.",
	"recalls player from dungeon to town, or from town to the deepest level of dungeon.",
	"completely protects you from any attacks at one in two chance.",
	"generates a magical triangle which damages all monsters in the area. The virtices of the triangle is you and two mirrors in sight. ",
	"generates barrier which completly protect you from almost all damages. takes a few your turns when the barrier breaks or duration time is exceeded.",
},

{
	"darken nearby area and inside of a room.",
	"detects visible monsters in the neighborhood and more and more. detects traps, doors and stairs at level 5, items at level 15. lights and know the whole level at level 45.",
	"teleport short distance.",
	"teleport as you recieve an attack. might be able to teleport just before recieveing damages at higher level.",
	"teleport long distance.",
	"attack and teleport in a time.",
	"attempt to freeze a monster.",
	"identifies an item.",
	"gives levitation for a while.",
	"generate a fire ball and teleport in a time. gives resistance to fire for a while. This resistance can be added to which from equipment for more powerful resistance.",
	"steps close to a monster and attacks at a time.",
	"shoots 8 iron Spikes in 8 random directions.",
	"teleport a monster to a place adjacent to you.",
	"releases a confusion ball which doesn't inflict any damage.",
	"swaps positions of you and a monster.",
	"sets a glyph under you. The glyph will explode when a monster moves on it.",
	"become ethereal form which gives ability to pass walls, and gives resistance to acid for a while. This resistance can be added to which from equipment for more powerful resistance.",
	"generates huge balls of poison, drain life and confusion, then teleport in a time.",
	"fires some number of beams of fire, nether or plasma in random directions.",
	"creates shadows of yourself which gives you abillity to completely evade any attacks at one in two chance for a while.",
	"",
},
};
#endif

