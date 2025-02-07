// 怪物攻城升级规模
#include <ansi.h>
#include <map.h>
#include <city.h>
#include <skill.h>
#include <equip.h>

inherit "/inh/std/virtual";

private static int War;                 // 战争状态  0 未开始 1 开始有怪物攻城 2 已结束
private static int Level;               // 战场等级


private static object *dbComrade = ({ });       // 怪物
private static object *dbPlayer = ({ });       	// 玩家

private static int Damage;		   	// 伤害


private static string City;			// 城市的名字

int is_copy_scene() {return 1;}

int get_real_z() {return 8860;}

// 函数：构造处理
void create()
{
        object me = this_object();

        if( !clonep(me) ) return;

        set_heart_timer( me, set_heart_timer_2(me, getoid(me) % 10) );    // 心跳随机
        set_heart_loop(me, 20);    // 循环心跳：５秒钟
        me->heart_beat();
        set_heart_beat(1);
        War = WAR_READY;
}

// 函数：获取战争状态
int get_war() { return War; }

// 函数：设置战争状态
int set_war( int flag ) { return War = flag; }

// 函数：获取名字
string get_city() { return City; }

// 函数：设置名字
string set_city( string flag ) { return City = flag; }

int get_level() { return Level;}

int set_level(int i, int j)
{
	string *cityname = ({ "齐国", "韩国", "赵国", "魏国", "秦国", "楚国", "燕国", });
	string *warname = ({ "玄武门", "朱雀门", "青龙门", "白虎门", });
	if (j>0&&j<8) set_city(cityname[j-1]);
	if (i<4) set_name(warname[i]);
	return Level=i;
}

// 函数：获取伤害
int get_damage() { return Damage; }

// 函数：设置伤害
int set_damage( int flag ) { return Damage = flag; }

void heart_beat() { }

private static int HeartSec = 0;        // 心跳计时

// 函数：获取心跳计时
int get_heart_sec() { return HeartSec; }

// 函数：设置心跳计时
int set_heart_sec( int point ) { return HeartSec = point; }

// 函数：增添心跳计时
int add_heart_sec( int point ) { return set_heart_sec(HeartSec + point); }

// 函数：获取攻击方士兵
object *get_comrade_dbase() { dbComrade -= ({ 0 });  return copy(dbComrade); }

// 函数：获取攻击方士兵
int sizeof_comrade_dbase() { dbComrade -= ({ 0 });  return sizeof(dbComrade); }

// 函数：增加攻击方士兵
void add_comrade( object npc ) { dbComrade = dbComrade + ({ npc }) - ({ 0 }); }

// 函数：删除攻击方士兵
void sub_comrade( object npc ) { dbComrade -= ({ npc, 0 }); }

// 函数：获取玩家
object *get_player_dbase() { dbPlayer -= ({ 0 });  return copy(dbPlayer); }

// 函数：获取玩家数目
int sizeof_player_dbase() { dbPlayer -= ({ 0 });  return sizeof(dbPlayer); }

// 函数：增加玩家
void add_player( object player ) { dbPlayer = dbPlayer + ({ player }) - ({ 0 }); }

// 函数：删除玩家
void sub_player( object player ) { dbPlayer -= ({ player, 0 }); }

// 函数：心跳处理(循环)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 ) { __FILE__ ->heart_beat_loop_callout( this_object(), effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8 ); }

// 函数：心跳处理(循环)(在线更新)
void heart_beat_loop_callout( object map, int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 )    // 每2秒处理
{
        int sec = map->add_heart_sec(2);
        int time, count, value, i, j, p, x, y, z, color, value2;
        string name, *attrib, *attrib2;
        object npc, *player;
        if (sec<600) return;
        if (map->get_war()==2) return;
	// 等十分钟开始刷怪
	player = map->get_player_dbase();
	if (sec==600)
	{
		send_user( player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "本城正受到邪恶怪物的侵袭！第一波的怪物将在60秒后开始发动进攻！" );
		return;
	}

        // 是否全部清理干净
        if (map->sizeof_comrade_dbase()>=250 )
        {
        	send_user( player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "因为攻击的怪物已经超出了本城可以承受的上限250只，此次任务彻底失败了。" );
        	send_user( player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "虽然大家竭尽全力征战，但本战我们还是失败了。期待大家下次再接再厉，发挥更出色的表现！" );
        	send_user( player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "你们可以使用"HIR"门派信物"NOR"等传送道具离开这个战场。" );
        	CHAT_D->sys_channel(0, HIY+map->get_city()+"的"+map->get_name()+"受到了怪物的大肆破坏，国力受到了严重的打击。" );
        	map->before_destruct();
//        	destruct(map);
        	return;
        }
        // 因为怪物攻击超过100，战争消失，自行检测
        if (map->get_damage()>=100)
        {
        	send_user( player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "因为本城受到的伤害超出了可以承受的上限100，此次任务彻底失败了。" );
        	send_user( player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "虽然大家竭尽全力征战，但本战我们还是失败了。期待大家下次再接再厉，发挥更出色的表现！" );
        	send_user( player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "你们可以使用"HIR"门派信物"NOR"等传送道具离开这个战场。" );
        	CHAT_D->sys_channel(0, HIY+map->get_city()+"的"+map->get_name()+"受到了怪物的大肆破坏，国力受到了严重的打击。" );
        	map->before_destruct();
        	return;
        }
        if (sec<660) return;
        map->set_war(1);
        sec -= 660;
        if (sec<=90*40+32)
        {
        	time = sec / 90;	// 第几拨怪物
        	count = (sec % 90)/2;
        	time ++;
        	attrib = "/quest/defence"->get_npc_attrib(map->get_level(), sprintf("%d", time));
        	if (attrib==0) return;
        	value = to_int(attrib[6]);
        	value2 = value;
        	if (value<16)
        	{
        		if (count>0) return;
        	}
        	else
        	{
        		if (count >= value/6) return;
        		value = value/16;
        	}
        	if (count==0)
        	{
        		send_user( player, "%c%c%d%s", 0x43, 6, 0, HIR "本城正受到邪恶怪物的侵袭！" );
        		send_user( player, "%c%c%d%s", 0x43, 6, 0,  sprintf(HIR "第%d波的怪物开始发动进攻！" , time));
        		send_user( player, "%c%c%d%s", 0x43, 6, 0,  sprintf(HIR "已有%d只怪物在发动进攻！" , map->sizeof_comrade_dbase()));        		
        	}
        	value = value/3;
//log_file("test.dat", sprintf("%s sec=%d time=%d, count=%d attrib=%s value=%d npc=%d\n", short_time(), sec, time, count, attrib[6], value, map->sizeof_comrade_dbase() ));
        	z = map->get_id();
		for (i=0;i<3;i++)
		{
			p = get_jumpin(z, i+2);
                        x = ( p % 1000000 ) / 1000;
                        y = p % 1000;
			for (j=0;j<value;j++)
			{
				p = get_valid_xy( z, x + random(5), y + random(5), IS_CHAR_BLOCK );
				if (p)
				{
		                        x = ( p % 1000000 ) / 1000;
		                        y = p % 1000;
				}
				if (value2==6)
				{
					if (time<40) npc = new ("/npc/war/1101");
					else npc = new ("/npc/war/1102");
				}
				else
					npc = new ("/npc/war/1100");
				switch(attrib[5])
				{
				case "空手":
				case "武器":
					npc->set_weapon_code(UNARMED);
					npc->set_caster(0);
					break;
				case "暗器":
					npc->set_weapon_code(THROWING);
					npc->set_caster(1);
					break;
				default:
					npc->set_weapon_code(UNARMED);
					npc->set_caster(1);
					break;
				}
				npc->set_level(to_int(attrib[4]));
				npc->set_char_picid(to_int(attrib[0]));
				if (attrib[1]=="－") color = 0;
				else sscanf(attrib[1], "%x", color);
				npc->set_head_color(color);
				attrib2 = ({attrib[2], attrib[3], attrib[5] });
				"/sys/npc/energy"->init_npc(npc, npc->get_level(), attrib2);
				if (value==2)
				{
					if (time<40)
					{
						npc->set_max_hp(npc->get_max_hp()*10);
						npc->set_hp(npc->get_max_hp());
						npc->set_cp(npc->get_cp()*105/100);
						npc->set_ap(npc->get_ap()*105/100);
					}
					else
					{
						npc->set_max_hp(npc->get_max_hp()*40);
						npc->set_hp(npc->get_max_hp());
						npc->set_cp(npc->get_cp()*110/100);
						npc->set_ap(npc->get_ap()*110/100);						
					}
				}

				npc->add_to_scene(z, x, y, 6);
				map->add_comrade(npc);
			}
		}
        }
        else
        {
        	// 是否全部清理干净
        	if (map->sizeof_comrade_dbase()==0)
        	{
        		CHAT_D->sys_channel(0, HIY"在勇士们的同心协力之下，终于击退了侵入"+map->get_city()+map->get_name()+"的怪物大军，感谢侠士们的鼎力相助！" );
        		send_user( player, "%c%c%d%s", 0x43, 6, 0, HIY"在勇士们的同心协力之下，终于击退了侵入"+map->get_city()+map->get_name()+"的怪物大军，感谢侠士们的鼎力相助！" );
        		send_user( player, "%c%c%d%s", 0x43, 6, 0, CHAT + HIY + "你们可以使用"HIR"门派信物"NOR"等传送道具离开这个战场。" );
	        	map->before_destruct();
        	}
        }
}

// 函数：消除之前处理
void before_destruct()
{
        object map, *char, npc;
        int i, size;

        map = this_object();

        if( arrayp( char = map->get_comrade_dbase() ) )
        {
                for( i = 0, size = sizeof(char); i < size; i ++ ) if( objectp( npc = char[i] ) )
                {
                        npc->remove_from_scene();
                        destruct(npc);
                }
        }
        // 当作是战场结束
        "/sys/party/defence"->add_end_count(1);
        map->set_war(2);
}

void init_place(object map)
{
	object npc, *all;
	int i, z;
	int * locate = ({ 87, 123 , 95, 129 , 95, 117 , 107, 126, 121, 111, 110, 102, 86, 140, 77, 134,  });
	z = map->get_id();
	// 箭塔
	for (i=0;i<8;i++)
	{
		npc = new ("/npc/war/1017");
		npc->set_level(map->get_level()/2);
		npc->add_to_scene(z, locate[2*i], locate[2*i+1], 2);
		set_block(z, get_x(npc), get_y(npc), FLY_BLOCK);
	}
}