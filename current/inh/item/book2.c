
#include <ansi.h>
#include <item.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;

// �������鼮ʶ��
// int is_book_2() { return 1; }

// �������鼮ʶ��
int get_item_type() { return ITEM_TYPE_BOOK_2; }

int get_record() {return 1;}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object item )
{
        string name, book, result;
        int skill, level, exp, i, pf, level2, maxlevel;
        object file, perform;

        skill = item->get_skill_id();
        name = item->get_skill_name();
        book = item->get_name();
        file = load_object( SKILL->get_skill_file(skill) );
	if (!file) return 0;

        if( !( level = me->get_skill(skill) ) )
        {
                send_user(me, "%c%s", '!', "����ȫ������" + book + "��");
                return 0;
        }
/*      if( level >= me->get_max_skill_level() )
        {
                send_user(me, "%c%s", '!', book + "��ֵ����һ����");
                return 0;
        }       */
        if (file->is_vita_skill()==1)
        {
	        level2 = me->get_level();
	        if (level2<10) maxlevel = 0;
	        else
	        if (level2<25) maxlevel = 39;
	        else
	        if (level2<35) maxlevel = 69;
	        else
	        if (level2<60) maxlevel = 99;
	        else maxlevel = 200;      
	        if (me->get_skill(skill)>=maxlevel)
	        {
	                notify( "��ĵȼ�������ѧϰ��������" );
	                return 0;
	        }	          
	}
	else	       
        if( level >= me->get_max_skill_level_3() )    // ���ƣ��ȼ������
        {
                send_user(me, "%c%s", '!', "�����鲻���Կ���" + book + "��");
                return 0;
        }

        level ++;
        me->set_skill(skill, level);        
	if (skill==670||skill==680)
	{
		// ���ó�ʼ������
		me->set_skill_degree(skill, 1);
		// �Զ�ѧϰ����ʹ�õļ���
		for (i=0;i<500;i++)
		{
			pf = skill * 100 + i;
			if ("/sys/item/product"->check_vita_skill(me, pf)) continue;
			perform = load_object( SKILL->get_perform_file(pf) );					
			if (perform)
			{
				if (perform->get_skill_color()) break;
				if (perform->get_skill_level()<=level) 
				{							
					"/sys/item/product"->add_vita_skill(me, pf);
					perform->can_perform(me);
				}
				else break;
			}
			if (i>40 && !perform) break;
		}	
	}         
        if (file->is_vita_skill()==1) log_file("lifeskill.txt",sprintf("%s %s %d %d %d\n",short_time(),me->get_id(),me->get_number(),skill,level));
        result = sprintf( HIC "���ġ�%s������ %d ����", name, level );
        send_user( me, "%c%s", '!', result );
        send_user(me, result);

        return 1;
}
