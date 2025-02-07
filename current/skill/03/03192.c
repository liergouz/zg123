
// 开关技能  TIPS:[PF_SWITCH]
#include <effect.h>
#include <ansi.h>
#include <skill.h>

#define THIS_SKILL      0319
#define THIS_PERFORM    03192
#define PF_FLAG        "03192"
#define PF_NAME        "金刚"

#define SKILL_LEVEL     30
#define SUB_YUAN        12
#define TIME_INTERVAL   2

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：30级\n    召唤自然界的灵气护体，自己进入防御状态。提升35％的物理防御力，但是物理攻击力力会下降50％。防御状态下，无法更换任何装备。";
        result = sprintf(HIC"%s\n" NOR "技能需求：%d级\n元气消耗：%d点\n冷却时间：%d秒\n    召唤自然界的灵气护体，自己进入防御状态。提升35％的物理防御力，但是物理攻击力力会下降50％。防御状态下，无法更换任何装备。\n    再次使用技能可还原为正常状态。\n", 
        	PF_NAME, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL);
        return result;
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_FLAG) )
                return sprintf( "金刚：\n　　提升35％的物理防御力，但是物理攻击力会下降50％。\n" );
        else    return sprintf( "金刚\n" );
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{	
	int enmity;
	if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) return 1;
        if( me->get_perform(PF_FLAG) )    // 关闭
        {
        	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 2, 0, get_d(me), 0 );
	        set_effect(me, EFFECT_PROGRESS2, 10);
	        me->set_progress_file(__FILE__);
		send_user(me, "%c%c%w%s", 0x5a, 0, 10, "金刚关闭中……");        	
		return 1;
        }        
        if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点元气。", SUB_YUAN );
                return 1;
        }        
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 2, 0, get_d(me), 0 );
	me->add_yuan( -SUB_YUAN );
	set_effect(me, EFFECT_PROGRESS2, 10);
	me->set_progress_file(__FILE__);
	send_user(me, "%c%c%w%s", 0x5a, 0, 10, "金刚释放中……");        	
	enmity = 60 + (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/30*50 ;
	CHAR_FIGHT_D->set_enmity1(me,enmity); 
	return 1;	
}

// 函数：法术处理
int into_effect( object me , string arg)
{
	if( me->get_perform(PF_FLAG) )    // 关闭
	{
		me->delete_perform(PF_FLAG);
		send_user(me, "%c%c%c", 0x5a, 1, 1);
		USER_ENERGY_D->count_ap(me);
		USER_ENERGY_D->count_dp(me);
	        send_user( me, "%c%w%w%c", 0x81, 3192, 0, EFFECT_GOOD );
	        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3192, 0, EFFECT_GOOD );
		
	}
	else
	{
		me->set_perform(PF_FLAG, 1);
		me->set_perform("03191", 0);
		send_user(me, "%c%c%c", 0x5a, 1, 1);
		USER_ENERGY_D->count_ap(me);
		USER_ENERGY_D->count_dp(me);	
	        send_user( me, "%c%w%w%c", 0x81, 3192, 30000, EFFECT_GOOD );
	        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3192, 1, EFFECT_GOOD );		
	        send_user( me, "%c%w%w%c", 0x81, 3191, 0, EFFECT_GOOD );
	        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3191, 0, EFFECT_GOOD );
	        
	}
}

void effect_break(object me, string arg)
{
	send_user(me, "%c%c%c", 0x5a, 1, 0);
	set_effect(me, EFFECT_PROGRESS2, 0 );	
}

// 函数：获取特技类型
int get_perform_type() { return ON_ME; }

// 函数：能否使用特技
void can_perform( object me )
{
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, TIME_INTERVAL, 0, PF_NAME );
                return;
        }	
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, PF_NAME );
}
