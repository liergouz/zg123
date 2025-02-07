
#include <ansi.h>
#include <item.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;
inherit COMBINED;

// 函数：书籍识别
// int is_book_2() { return 1; }

// 函数：书籍识别
int get_item_type() { return ITEM_TYPE_BOOK_2; }

int get_record() {return 1;}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
        string name, book, result, perform;
        int skill, level, exp, pf;
        object file;

        skill = item->get_skill_id();
        name = item->get_skill_name();
        book = item->get_name();
        if (" " + me->get_fam_name()!=item->get_family_name())
        {
                send_user(me, "%c%s", '!', "你不是"+item->get_family_name()+" 的玩家，无法领会"+item->get_name()+"的奥义。");
                return 0;
        }  
        if( !( level = me->get_skill(skill) ) )
        {
                send_user(me, "%c%s", '!', "您完全看不懂" + book + "。");
                return 0;
        }      
        if( level < item->get_skill_level() )
        {
                send_user(me, "%c%s", '!', "您的"+item->get_skill_name()+"等级不足"+sprintf("%d", item->get_skill_level())+"级，无法领会该书的意义。");
                return 0;
        }       
        if (me->get_save(item->get_perform_id()))
        {
                send_user(me, "%c%s", '!', "您已经习得法术" + book + "，无需再使用该书籍了。");
                return 0;
        }
	me->set_save(item->get_perform_id(), 1);
	pf = to_int(item->get_perform_id());
	if(   ( file = load_object( SKILL->get_perform_file(pf) ) ) )
	{
		file->can_perform(me);
		send_user(me, "%c%s", '!', "您修得了新技能" + book + "。");
	}
        return 1;
}
