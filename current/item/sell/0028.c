
#include <equip.h>
#include <effect.h>

inherit TALISMAN;

int get_item_value() {return 20 ;}
int get_item_value_2() {return 20 ;}
int get_item_number() {return 10001023 ;}
int get_item_color() {return 1 ;}

int get_no_repair() {return 1;}

// 函数：法宝识别
int get_talisman_type() { return 13; }
//不是完成任务时不掉耐久度
int add_lasting( int time )
{
	if ( time < 0 && time > -100 )
		return 0;
	return ::add_lasting(time);	
}
int add_potential(int pot,object who) 
{
	int i;
	object item=this_object();
	
	if ( who->get_online_rate() != 100 )
		return 0;
	pot = pot * 3 / 10;
	if ( add_lasting(-100) <= 0 )
	{
		send_user(who,"%c%s",'!',sprintf("你的%s应声碎裂，消失得无影无踪。",get_name()));
		item->remove_from_user();
		destruct(item);
	}
	return pot;	
}
// 函数：构造处理
void create()
{
        object me = this_object();

        set_name( "尚方咸鱼" );
        set_picid_1(4213);
        set_picid_2(4213);
        set_value(10);
        set_level(1);
        set_max_lasting(1099);

        setup();

}

string get_short()
{
	return "每次成功完成师爷杀囚任务获得1.3倍的潜能奖励。可使用10次。";
}

// 函数：获取描述
string get_desc() 
{ 
        return "御赐的咸鱼，10次有效。\n装备后做师爷杀囚任务获得1.3倍潜能。\n（每成功完成一次耐久度减一）";
}
