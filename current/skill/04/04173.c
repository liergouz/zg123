
// 召唤技能  TIPS:[PF_CALL]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0417
#define THIS_PERFORM    04173
#define PF_START       "04173"
#define PF_NAME        "法力转移"
#define TIME_INTERVAL	2

#define SKILL_LEVEL     7
#define SUB_MP          ( 30 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 30 )


// 函数：获取符法效果
int get_cast_seal() { return 9103; }    // 符纸逆旋

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：7级\n    将该技能消耗法术力的150％转移到召唤兽身上。";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC"%s(%d级)\n" NOR "技能需求：%d级\n法力消耗：%d点\n冷却时间：%d秒\n    将该技能消耗法术力的150％转移到召唤兽身上。\n" HIC"下一级：\n"NOR"技能需求：" HIR "%d级" NOR"\n    使用该技能消耗法力%d点。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, 2, cur_level*10+SKILL_LEVEL, SUB_MP + 20 );
        return result;	
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{

	object * user, soldier, * zombie;
	int flag = 0;
	int i, size, mp;
	if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;
        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }	
        who = me->get("soldier");
        if (!who) return 1;
	if (who->get_owner()!=me)
        {
                printf( ECHO "对方不是您的召唤生物。" );
                return 1;
        }	
        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );        
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );        
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);	
        who->add_mp(mp*3/2);
        me->add_mp(-mp);
        send_user( me, "%c%c%d%c", 0x2c, 4, getoid(who), (who->get_mp()+1)*50/(who->get_max_mp()+1));
        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 4173, 2, OVER_BODY, PF_ONCE );
	me->set_perform( PF_START, time() );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
	CHAR_FIGHT_D->set_enmity2(me,who,20);
        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
        return 2;    // 执行成功
}

// 函数：获取特技类型
int get_perform_type() { return ON_ME; }

// 函数：能否使用特技
void can_perform( object me )
{
        int interval;
        string name;

        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }
	name = sprintf("%s(%d级)", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/10+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0, 1, MAGIC_ACT_BEGIN, 0, 5, 0);
}
