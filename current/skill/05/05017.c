
// 自用持续技能  TIPS:[PF_SELF_LOOP]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0501
#define THIS_PERFORM    05017
#define PF_START       "05017"
#define PF_TIME        "05017#"
#define PF_NAME        "强化金针渡厄"

#define SKILL_LEVEL     21
#define TIME_INTERVAL   2
#define SUB_MP          120 + (me->get_skill(THIS_SKILL) - 10)/11*60
#define ADD_EFFECT      ( 20 + ( me->get_skill(THIS_SKILL)-10) / 11 * 20 )

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n技能需求：21级\n道具消耗：神农宝典\n    强化金针渡厄，同时对视线范围内的队伍所有成员施展法术金针渡厄。";
        result = sprintf(HIC"%s\n" NOR "技能需求：%d级\n道具消耗：神农宝典\n法力消耗：%d点\n冷却时间：%d秒\n    强化金针渡厄，同时对视线范围内的队伍所有成员施展法术金针渡厄。\n",
        	PF_NAME, SKILL_LEVEL, SUB_MP, TIME_INTERVAL );
	return result;
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int level, interval, mp, z, add, level2;
        object *user, owner, item;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;
        if (me->get_save("05017")==0) return 1;

        interval = TIME_INTERVAL;

        if( gone_time( me->get_perform(PF_START) ) < interval ) return 1;    // 小心准备 level

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 level
        {
                printf( ECHO "使用“" PF_NAME "”需要 %d 点法力。", mp );
                return 1;
        }        
        if( !objectp( item = present("神农宝典", me, 1, MAX_CARRY*4) ) )
        {
                printf( ECHO "您得有神农宝典才能使用“" PF_NAME "”。" );
                return 1;
        } 
        item->add_amount(-1);             
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );

        me->add_mp(-mp);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
	return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        int level, interval, mp, x, y, z, add, level2, i, size, effect;
        object *user, who, owner, *char;
        string arg;
        interval = 900;

	level = me->get_skill(THIS_SKILL);
        interval = 900;    // 小心准备 me
        effect = ADD_EFFECT;    // 小心准备 me	
        me->set_perform( PF_TIME, interval );
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 3292, 1, OVER_BODY, PF_ONCE );
        send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        z = get_z(me), x = get_x(me), y = get_y(me);
        char = get_range_object(z, x, y, 10, USER_TYPE) + get_range_object(z, x, y, 10, CHAR_TYPE);
        size = sizeof(char);
	for (i=0;i<size;i++) if (who = char[i])
	{
		if (who->is_anti_effect()) continue;
		if (who->is_user() && (me!=who))
		{
			if (!me->get_leader()||me->get_leader()!=who->get_leader()) continue;
		}
		if (who->is_npc())
		{
			owner = who->get_owner();
			if (!owner) continue;
			if (!me->get_leader()||me->get_leader()!=owner->get_leader()) continue;
		}
	        level2 = who->get_level();
	        if (level - 10 - level2>0) effect = effect - (level - 10 - level2)/11*20;
		
	        if( get_effect(who, EFFECT_CHAR_POWERUP2) )
	        {
	        	if (who->is_user() && who->get_save("05012")>effect) return 1;
	        	if (who->is_npc() && who->get("05012")>effect) return 1;
	        }
	        set_effect(who, EFFECT_CHAR_POWERUP2, interval);
	        if (who->is_user() )
	        {
			who->set_save("05012", effect);
			USER_ENERGY_D->count_cp(who);
		}
		else
	        {
	        	who->add_cp(-who->get("05012"));
			who->set("05012", effect);
			who->add_cp(effect);
		}	
		send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 50119, 1, OVER_BODY, PF_ONCE );                
	        send_user( who, "%c%w%w%c", 0x81, 5012, get_effect_3(who, EFFECT_CHAR_POWERUP2), EFFECT_GOOD );
	        send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 5012, 1, EFFECT_GOOD );
	}
        return 2;    // 执行成功
}

// 函数：获取特技类型
int get_perform_type() { return ON_ME; }

// 函数：能否使用特技
void can_perform( object me )
{
        int interval;
        string name;
        if (me->get_save("05017")==0) return;
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
	send_user(me, "%c%w%w%c%c%c%c%c%s", 0x64, THIS_PERFORM, SUB_MP, 0,1, MAGIC_ACT_BEGIN, 0, 5, "神农宝典");
}

void effect_done(object me)
{
	if (me->is_user())
	{
		me->set_save("03291#", 0);
		USER_ENERGY_D->count_dp(me);
	}
	else
	{
		me->add_dp(-me->get("03291#"));
		me->set("03291#", 0);					
	}
        send_user( me, "%c%w%w%c", 0x81, 3291, 0, EFFECT_GOOD );
        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3291, 0, EFFECT_GOOD );

}

void effect_done2(object me)
{
	if (me->is_user())
	{
		me->set_save("03292#", 0);
		USER_ENERGY_D->count_pp(me);
	}
	else
	{
		me->add_pp(-me->get("03292#"));
		me->set("03292#", 0);
					
	}	
        send_user( me, "%c%w%w%c", 0x81, 3292, 0, EFFECT_GOOD );
        send_user( get_scene_object_2(me, USER_TYPE) - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3292, 0, EFFECT_GOOD );

}