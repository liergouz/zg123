
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

// �����������
int main( object me, string arg )
{
        string result, arg2;
	int type, i, size;
	object *inv, item;

        if( is_player(me) )
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }


        if( arg ==0  )
        {
        	result = sprintf("��ѡ���������ã�\n");
        	if (me->get_save("no_hurt"))
        		result += ESC "ȡ���޵�\ngmset no_hurt 0\n";
        	else
        		result += ESC "�޵�\ngmset no_hurt 1\n";
		if (me->get_save("no_visible"))
			result += ESC "ȡ������\ngmset invisible 0\n";        	
		else
			result += ESC "����\ngmset invisible 1\n"; 
		result += ESC "���������Ʒ\ngmset clear\n"; 
		result += ESC "��Ѫ�ӱ�\ngmset double\n"; 
		result += ESC "��Ѫ�ָ�����\ngmset normal\n"; 
		result += ESC "��Ѫ����ȫ��\nrecover\n"; 
		result += ESC "ȡ��\n"; 
		send_user( me, "%c%s", ':', result);
                return 1;
        }
        if (arg=="clear")
        {
        	inv = all_inventory(me, 1, MAX_CARRY*4);
        	for( i = 0, size = sizeof(inv); i < size; i ++ ) if( objectp( item = inv[i] ) )
        	{
        		item->remove_from_user();
        		destruct(item);
        	}
        	notify( "���ĵ����������" );
        	return 1;
        }
        if (arg=="double")
        {
        	me->set_max_hp(me->get_max_hp()*2);
        	me->set_hp(me->get_max_hp());
        	return 1;
        }
        if (arg=="normal")
        {
        	"/sys/user/energy"->count_max_hp(me);
        	return 1;
        }        
        if (sscanf(arg, "%s %d", arg2, type)!=2) return 1;
        switch(arg2)
        {
        case "no_hurt":
        	me->set_save("no_hurt", type);
        	if (type==1) notify( "������Ϊ�޵�״̬��" );
        	else notify( "��ȡ�����޵�״̬��" );
        	break;
        case "invisible":
        	if (type==1)
        	{
	        	set_effect_2( me, EFFECT_CHAR_INVISIBLE, 100, 10 );    // ÿʮ���Ѫ
        		CHAR_CHAR_D->init_loop_perform(me);
	        	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9000, 1, UNDER_FOOT, PF_LOOP );    // ��͸��
			set_invisible(me, 1);
			me->set_save("no_visible", 1);
			send_user( me, "%c%c%c", 0x3d, 241, 2 );
		}
		else
		{
			set_effect_2( me, EFFECT_CHAR_INVISIBLE, 0, 0);
			me->set_save("no_visible", 0);
			set_invisible(me, 0);
			CHAR_CHAR_D->init_loop_perform(me);
			send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9000, 1, UNDER_FOOT, PF_STOP );			
		}
		break;
        }
        return 1;
}
