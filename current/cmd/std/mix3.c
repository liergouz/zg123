#include <item.h>
#include <ansi.h>
#include <equip.h>

int check_match(object equip, object diamond);
int mix1(object me,object *item);

// �����������
int main( object me, string arg )
{
        object *item, who;
        string name, make, result,forge,index;
        int *id;
        int i, flag, level, rate;

        if( !arg ) return 1;

        item = ({ 0, 0, });  id = ({ 0, 0, });

        if( sscanf( arg, "? %s %x# %x#", name, id[0], id[1] ) == 3 ) flag = 1;
        else if( sscanf( arg, "%s %x# %x#", name,
                id[0], id[1] ) == 3 ) flag = 2;
        else
        {
                notify( "���뾫��ʲô������" );
                return 1;
        }
/*
        if( !objectp( who = find_char(name) ) ) return 1;

        if( !who->is_maker() ) return 1;

        if( !inside_screen_2(me, who) )
        {
                notify( "������%s̫Զ�ˡ�", who->get_name() );
                return 1;
        }

        me->to_front_eachother(who);
*/
        if( flag == 1 )	//�����ɹ���
        {
                for( i = 0; i < 2; i ++ )
                {
                        if( !objectp( item[i] = present( sprintf("%x#", id[i]), me, 1, MAX_CARRY * 4 ) ) )    // ��Ʒ�Ƿ���ڣ�
                        {
                        	send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
                            	return 1;
                        }
                }
		if (item[1]->get_item_type()!=ITEM_TYPE_DIAMOND_3)
		{
			send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
			return 1;
		}
		if(item[1]->get_diamond_type() != "forge")//�жϾ�ʯ��װ���Ƿ�ƥ�䡣
		{
			make = item[0]->get("make");
			level = item[1]->get_level();
			if (make==0) make = "";
			if (strlen(make)!=level-1)
			{
				send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
				return 1;
			}	
			if (check_match(item[0], item[1])==0)
			{
				send_user( me, "%c%c%c%d", 0x25, 0, 0, 0 );
				return 1;
			}		
		}
		else//�ж϶���ʯ��װ���Ƿ�ƥ�䡣
		{
			forge = item[0]->get("forge");//�����ǻ��װ�����Ǽ���
			if (forge==0) forge = "";
			level = strlen(forge);
			index = item[1]->get_forge_index();
			if((level == 1||level == 0) && index!="1")
			{
				notify( "����ʯ���Ͳ������޷�����" );
				return 1;
			}
			if((level == 2||level == 3) && index!="2" )
			{
				notify( "����ʯ���Ͳ������޷�����" );
				return 1;
			}
			if(level >= 4)
			{
				if((index!="3" && index!="4"))
				{
					notify( "����ʯ���Ͳ������޷�����" );
					return 1;	
				}
			}
		}
		if(item[1]->get_diamond_type() == "forge")//�����Ǽ������ʯ����װ���ĳɹ���
		{
			rate = 30000;
			for(i=4;i<=level;i++)
			{
				rate = rate;
			}
			rate = rate / 100;
		}
		else//�����Ǽ��㾧ʯ����װ���ĳɹ��ʡ�
		{
			switch(level)
			{
			case 1: rate = 100; break;
			case 2: rate = 100; break;
			case 3: rate = 100; break;
			case 4: rate = 100; break;
			case 5: rate = 100; break;
			case 6: rate = 100; break;
			case 7: rate = 100; break;
			case 8: rate = 100; break;
			case 9: rate = 100; break;
                        case 10: rate = 100; break;
                        case 11: rate = 100; break;
                        case 12: rate = 100; break;
                        case 13: rate = 100; break;
                        case 14: rate = 100; break;
	       		default: rate = 15; break;
			}	
		}
		if(level!=1 && me->get_vip() && !me->get_save_2("vip_package.trial"))
			rate += 5;
		send_user( me, "%c%c%c%d", 0x25, 0, rate, 0 );
		return 1;
        }
        else	//����װ��
        {
                for( i = 0; i < 2; i ++ )
                {
                        if( !objectp( item[i] = present( sprintf("%x#", id[i]), me, 1, MAX_CARRY * 4 ) ) )    // ��Ʒ�Ƿ���ڣ�
                        {
                            	return 1;
                        }
                }
		if (item[1]->get_item_type()!=ITEM_TYPE_DIAMOND_3)
		{
			notify( "������Ҫһ����ʯ��" );
			return 1;
		}
		if ( item[1]->get_diamond_type() == "forge" )
	        {
	        	return	mix1( me,({item[0],item[1]}) );	//����ʯ����װ��
	        }
		if ( item[1]->get_mix_level() && item[0]->get_level() > item[1]->get_mix_level())
		{
			notify( sprintf("�Բ����������ڸ���%d����װ����ʹ�øþ�ʯ��" ,item[1]->get_mix_level()));
			return 1;
		}
		make = item[0]->get("make");
		level = item[1]->get_level();
		if (make==0) make = "";
		if (strlen(make)!=level-1)
		{
			notify( "��ʯ��װ���ľ����ȼ���ƥ�䡣" );
			return 1;
		}
		if (check_match(item[0], item[1])==0)
		{
			notify( "��ʯ���Ͳ������޷�����" );
			return 1;
		}
		switch(level)
		{
		case 1: rate = 100; break;
		case 2: rate = 100; break;
		case 3: rate = 100; break;
		case 4: rate = 100; break;
		case 5: rate = 100; break;
		case 6: rate = 100; break;
		case 7: rate = 100; break;
		case 8: rate = 100; break;
		case 9: rate = 100; break;
                case 10: rate = 100; break;
	        default: rate = 11; break;
		}
		if(level!=1 && me->get_vip() && !me->get_save_2("vip_package.trial"))
			rate += 5;
	        if (random100()<rate)
	        {
	        	item[0]->add(item[1]->get_diamond_type(), item[1]->get_diamond_add());
	        	make += item[1]->get_diamond_index();
	        	item[0]->set("make", make);
	        	if (item[1]->is_record())
	        	{
				result = sprintf("�����ɹ���ʧ %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[1]->get_name(), "/sys/item/item"->get_pawn_save_string(item[1]), 1, item[1]->get_user_id(), get_z(me), get_x(me), get_y(me) );
				"/sys/user/cmd"->log_item(result);
			}
		        item[1]->remove_from_user();
		        destruct( item[1] );
		        send_user( me, "%c%d%c", 0x31, getoid(item[0]), 0 );
	        	write_user( me,	ECHO "%s�����ɹ�����õ���%s��%d��", item[0]->get_name(), item[0]->get_name(), level );
	        	if (level>=9)
	        	{
	        		result = HIY+ sprintf("��ϲ%s(%d)�ɹ���%s������%d��", me->get_name(), me->get_number(), item[0]->get_name(), level);
	        		CHAT_D->sys_channel( 0, result );
	        	}
	        }
	        else
	        {
	        	if (item[1]->is_record())
	        	{
		        	result = sprintf("����ʧ����ʧ %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[1]->get_name(), "/sys/item/item"->get_pawn_save_string(item[1]), 1, item[1]->get_user_id(), get_z(me), get_x(me), get_y(me) );
				"/sys/user/cmd"->log_item(result);
			}
		        item[1]->remove_from_user();
		        destruct( item[1] );
		        write_user( me,	ECHO "%s����ʧ�ܣ�", item[0]->get_name());
	        }
	        return 1;
        }

        return 1;
}

int check_match(object equip, object diamond)
{
	string type = diamond->get_diamond_type();
	switch(equip->get_equip_type())
	{
	case HEAD_TYPE:
	case ARMOR_TYPE:
		if (type=="hp") return 1;
		if (type=="mp") return 1;
		if (type=="dp") return 1;
		if (type=="pp") return 1;
		break;
	case NECK_TYPE:
		if (type!="double" && type!="double2") return 1;
		break;
	case WEAPON_TYPE:
		if (type=="ap") return 1;
		if (type=="cp") return 1;
		if (type=="!%") return 1;
		if (type=="double") return 1;
		if (type=="double2") return 1;
		break;
	case WAIST_TYPE:
		if (type!="ap" && type!="cp" && type!="double" && type!="double2") return 1;
		break;
	case BOOTS_TYPE:
		if (type!="ap" && type!="cp" && type!="!%" && type!="double" && type!="double2") return 1;
		break;
	}
}
//����ʯ����װ��
int mix1(object me,object *item)
{
	int level,rate,rate1,i,color,bind;
	string forge,result, index;
	if ( !(i=item[0]->get_equip_type())
		|| (i!=WEAPON_TYPE&&i!=ARMOR_TYPE&&i!=HEAD_TYPE&&i!=BOOTS_TYPE&&i!=WAIST_TYPE&&i!=NECK_TYPE))
		return 0;
	forge = item[0]->get("forge");
	index = item[1]->get_forge_index();
	if (index<"1" || index >"4") return 0;
	if (forge==0) forge = "";
	level = strlen(forge);
	if (item[1]->get_level()!=1)
	{
		notify( "����һ���Ķ���ʯ���ҹ����ֽ⡣" );
		return 1;
	}
	if (index=="1")
	{
		if (level>1)
		{
			notify( "��������ʯֻ�ܶ�����2�����µ�װ���ϡ�" );
			return 1;
		}
	}
	if (index=="2")
	{
		if (level>3)
		{
			notify( "�м�����ʯֻ�ܶ�����4�����µ�װ���ϡ�" );
			return 1;
		}
	}
	bind = item[0]->get_bind();
	if ( me->get_level()/10 < level+1 )
	{
		notify( "��ĵȼ����㡮װ��������10��������������װ����" );
		return 0;
	}
	color = item[0]->get_item_color();
	rate = 30000;
	for(i=4;i<=level;i++)
		rate = rate;
	rate = rate / 100;
	if ( me->get_vip() && !me->get_save_2("vip_package.trial") )
		rate += 5;
	rate1 = random100();
	if ( is_god(me) )
	{
		if (me->get("lb")) rate1 = me->get("lb");
		tell_user(me,"����ɹ��� %d ���ڼ��� %d",rate,rate1);
	}
        if (rate1<rate)
        {
        	forge += item[1]->get_forge_index();
        	if (item[1]->is_record())
        	{
			result = sprintf("�����ɹ���ʧ %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[1]->get_name(), "/sys/item/item"->get_pawn_save_string(item[1]), 1, item[1]->get_user_id(), get_z(me), get_x(me), get_y(me) );
			"/sys/user/cmd"->log_item(result);
		}

		ITEM_EQUIP_D->init_equip_prop_5(item[0]);
	        if (color!=0) "/sys/sys/count"->add_equip("blue", -1);
        	item[0]->set("forge", forge);
	        item[1]->remove_from_user();
	        destruct( item[1] );
	        send_user( me, "%c%d%c", 0x31, getoid(item[0]), 0 );
	        level = strlen(forge);
        	write_user( me,	ECHO "��ϲ���ɹ��ض����һ��%d�Ǽ�װ����", level );
        	if (level>=9)
        	{
        		result = HIY+ sprintf("��ϲ%s�ɹ��ض����һ��%d�Ǽ�װ����", me->get_name(), level);
        		CHAT_D->sys_channel( 0, result );
        	}
        }
        else
        {
        	if (item[1]->is_record())
        	{
	        	result = sprintf("����ʧ����ʧ %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[1]->get_name(), "/sys/item/item"->get_pawn_save_string(item[1]), 1, item[1]->get_user_id(), get_z(me), get_x(me), get_y(me) );
			"/sys/user/cmd"->log_item(result);
		}
		if (item[1]->get_forge_index()=="4")
		{
		 	ITEM_EQUIP_D->reduce_equip_prop(item[0]);
		 	write_user( me,	ECHO "ʮ�ֲ��ң�����ʧ���ˡ����%s�����½�һ�ǡ�", item[0]->get_name());			
		}
		else
		{
			item[0]->delete("forge");
		 	ITEM_EQUIP_D->reset_equip_prop(item[0]);
		 	write_user( me,	ECHO "ʮ�ֲ��ң�����ʧ���ˡ����%s����ԭ��δ����״̬��", item[0]->get_name());
		}
 	    	send_user( me, "%c%d%c", 0x31, getoid(item[0]), 0 );
	        item[1]->remove_from_user();
	        destruct( item[1] );
        }
        return 1;


}
