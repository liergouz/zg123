
#include <ansi.h>
#include <item.h>
#include <skill.h>
#include <effect.h>

inherit ITEM;
inherit USABLE;

// 函数：书籍识别
// int is_book() { return 1; }

// 函数：书籍识别
int get_item_type() { return ITEM_TYPE_BOOK; }

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
        object file;
        string name, book, result;
        int skill, level, exp, maxlevel;

        skill = item->get_skill_id();
        name = item->get_skill_name();
        book = item->get_name();

        if( !( level = me->get_skill(skill) ) )
        {
                send_user(me, "%c%s", '!', "您完全看不懂" + book + "。");
                return 0;
        }
/*      if( level >= me->get_max_skill_level() )
        {
                send_user(me, "%c%s", '!', book + "不值得您一看。");
                return 0;
        }       */
        if( level >= me->get_max_skill_level_3() )    // 限制：等级、最高
        {
                send_user(me, "%c%s", '!', "您经验不足以看懂" + book + "。");
                return 0;
        }
	if (skill>=610&&skill<=680)
	{
	        level = me->get_level();
	        if (level<10) maxlevel = 0;
	        else
	        if (level<25) maxlevel = 39;
	        else
	        if (level<35) maxlevel = 69;
	        else
	        if (level<60) maxlevel = 99;
	        else maxlevel = 200;
	        if (me->get_skill(skill)>=maxlevel)
	        {
	                notify( "你的等级不足于学习这样技能" );
	                return 0;
	        }
	}	               
        if( get_effect(me, EFFECT_USER_STUDY) ) 
        {
                skill = me->get_save("study");
                result = ( file = load_object( SKILL->get_skill_file(skill) ) ) ? file->get_name() : "未知技能";
                send_user(me, "%c%s", '!', "您正在研读" + result + "之中。" );
                return 0;
        }

        me->set_save("study", skill);
        set_effect_2(me, EFFECT_USER_STUDY, 60, 60);
        write_user( me, ECHO "您开始研读《%s》。", book );

        return 1;
}
