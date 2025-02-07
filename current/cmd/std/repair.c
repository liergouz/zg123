
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <music.h>
#include <item.h>

// �����������
int main( object me, string arg )
{
        object city, who, item, *inv;
        string id, legend;
        int level, tax, value, size, flag, i, allvalue, last, itemid;
        string result;

        if( gone_time( me->get_time("repair") ) < 1 )    // ʱ������
        {
                me->set_time( "repair", time() );
                return 1;
        }
        me->set_time( "repair", time() );

        if( !arg ) return 1;
        else if( sscanf( arg, "<< %s %s", id, arg ) == 2 ) flag = 8;
        else if( sscanf( arg, "< %s %s", id, arg ) == 2 ) flag = 7;                
        else if( sscanf( arg, "!! %s %s", id, arg ) == 2 ) flag = 5;
        else if( sscanf( arg, "! %s %s", id, arg ) == 2 ) flag = 4;        
        else if( sscanf( arg, ">> %s %s", id, arg ) == 2 ) flag = 3;        
        else if( sscanf( arg, "> %s %s", id, arg ) == 2 ) flag = 2;    
        else if( sscanf( arg, "* %s", id ) == 1 ) flag = 6;             
        else if( sscanf( arg, "%s %s", id, arg ) == 2 ) flag = 1;               
        else id = arg;

        if( !objectp( who = find_char(id) ) ) return 1;

        if( !who->is_repairer() ) return 1;

        if( !inside_screen_2(me, who) )
        {
                notify( "������%s̫Զ�ˡ�", who->get_name() );
                return 1;
        }

        if( flag == 0 )
        {
        	if (me->get_skill(650))
	                send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), 
        	                sprintf("%s��\n    %s\n��������Ҫʲô����\n"
        	                ESC "��Ҫ����װ��\nrepair %x# identify\n"
                                ESC "��Ҫ�ֽ�װ��\nrepair * %x#\n"
                                ESC "����Ҫ��ͨ����\nrepair %x# 2\n"
                                ESC "��ֻ�Ǿ�����������\nCLOSE\n", who->get_name(), "/quest/word"->get_normal_word(who),  getoid(who), getoid(who), getoid(who) ) );                
        	else
                	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), 
                        	sprintf("%s��\n    %s\n��������Ҫʲô����\n"
//                                ESC "����Ҫ��������������\nrepair %x# 1\n"
				ESC "��Ҫ����װ��\nrepair %x# identify\n"
                                ESC "����Ҫ��ͨ����\nrepair %x# 2\n"
                                ESC "��ֻ�Ǿ�����������\nCLOSE\n", who->get_name(), "/quest/word"->get_normal_word(who),  getoid(who), getoid(who) ) );                
                return 1;
        }
        if (flag==1)
        {
        	if (arg=="identify")
        	{
        		send_user( me, "%c%c%d", 0x61, 1, getoid(who) );
        		return 1;
        	}
        	if (arg=="1") send_user( me, "%c%c%d", 0x52, 2, getoid(who) );
        	else send_user( me, "%c%c%d", 0x52, 1, getoid(who) );
        	return 1;
        }
        if (flag==6)
        {  	
        	send_user( me, "%c%c%d", 0x60, 10, getoid(who) );
        	return 1;
        }
        if (flag==7 || flag==8)
        {
        	item = present(arg, me,	0, 0);
        	if (!item) return 1;
	        if( !item->is_equip() )
	        {
	                return 1;
	        }
	        if (item->get_equip_type() == HAND_TYPE)
	        {
	        	return 1;
	        }
	        if (item->get_equip_type() == 0)
	        {
	        	return 1;
	        }	        
	        if (!item->get_hide()||item->get_level()<30)
	        {
	        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
	                	sprintf("%s��\n    %s�Ѿ��������ˡ�"
	                        , who->get_name(), item->get_name() ) );
			return 1;
	        }        	
	        level = item->get_level();
	        level *= 30;
	        if (level==0) level = 30;	   
	        if (flag==7)
	        {
			send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
		                sprintf("%s��\n    �������װ����Ҫ%d���Ƿ������Ҫ������\n"
		                ESC "�ǵģ���Ҫ����\nrepair << %x# %x#\n"
		                ESC "̫���ˣ��Ҳ�������\nCLOSE\n", who->get_name(), level, getoid(who), getoid(item) ) );	        	
	        	return 1;
	        }   
	        if (me->get_cash()<level)
	        {
	        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
	                	sprintf("%s��\n    ����ֽ���%d���޷�����%s��"
	                        , who->get_name(), level, item->get_name() ) );
			return;        	
	        }        
	        me->add_cash2(-level);
	        legend = sprintf("���� %s,%d,%s,%s @%s �� 0 %d 0 %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), who->get_name(), level, get_z(me), get_x(me), get_y(me) );
		"/sys/user/cmd"->log_item(legend);
		"/sys/sys/count"->add_use("����", level);   
		if (item->get_item_color()==0 || item->get_item_color()==4 )
		{
			i = random(10000);
			if (i==0)
				"/sys/item/equip"->init_equip_prop_3(item);
			else
			if (i<301)
				"/sys/item/equip"->init_equip_prop_1(item);
			if (item->get_item_color()!=0 && item->get_item_color()!=4)
			{
				itemid = "/sys/sys/id"->add_max_itemid(1);
				item->set_user_id( sprintf("#%d#", itemid) );
				log_file("itemid.dat", sprintf("%s %d %s %s\n", short_time(), itemid, item->get_name(), "/sys/item/item"->get_pawn_save_string(item) ));				
				legend = sprintf("�������� @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", who->get_name(), me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
				"/sys/user/cmd"->log_item(legend);			
			}
		}
		item->set_hide(0);
		level = get_d(item);
		item->add_to_user(level);     
		level = item->get_item_color();
		switch(level)
		{
		case 0:
		case 4:
			result = "���װ������ͨ��ûʲô�ر�ġ�";
			break;
		case 1:
			result = "���װ������һ�������װ����";
			break;
		case 2:
			result = "����һ�����ѵõ����װ������ϲ�㡣";
			break;
		default:
			result = "����һ��ϡ����Ʒѽ�����������ܿ���������һ�����";
			break;
		}
		send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(),
	                sprintf("%s��\n    %s\n"
	                ESC "��������\nrepair %x# identify\n"
	                ESC "�뿪\nCLOSE\n"
			, who->get_name(), result, getoid(who) ) );
		return 1;	          
        }
        me->to_front_eachother(who);
        if( city = CITY_D->get_city_object(who) )
        {
                if( me->get_city_name() == who->get_city_name() )
                        tax = city->get_buy_tax();
                else    tax = city->get_buy_tax_2();                
        }
        else	tax = 0;        
        if (arg=="all")
        {
        	allvalue = 0;
        	inv = me->get_all_equip();
        	for( i = 0, size = sizeof(inv); i < size; i ++ ) 
        	{
        		if (objectp(inv[i]))
        		{
        			item = inv[i];
        			if( !item->is_equip() ) continue;
//        			if( item->get_equip_type() == HAND_TYPE ) continue;
        			if( item->get_weapon_code() == THROWING ) continue;
        			if( item->get_equip_type() == HAND_TYPE ) continue;
        			if( item->get_equip_type() == FAMILY_TYPE ) continue;
        			if( item->get_max_lasting() < 10 ) continue;
        			if( item->get_lasting() >= item->get_max_lasting() ) continue;
        			if( ( value = item->get_value() ) <= 0 ) continue;
			        if( item->is_combined() ) value *= item->get_amount();
			        value = value - value * item->get_lasting()/item->get_max_lasting();
				if( item->get_equip_type() == HAND_TYPE && item->get_lasting()!= item->get_max_lasting() ) value = 100000;
			        if( flag == 3 || flag== 5 ) value *= 8;    // ��������        			
        			value += value * tax / 100;
        			if (value<10) value = 10;        			
        			allvalue += value;
        		}
        	}
		if( me->get_cash() < allvalue )
		{
		        notify( "���������������װ����Ҫ %d �������ϵ��ֽ𲻹���",  allvalue );
		        return 1;
		}       
		if( allvalue <=0 )
		{
		        notify( "�������װ��Ŀǰ�ܺã�û�б�Ҫ����" );
		        return 1;
		}		        
		if (flag==2)
		{
		        send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), 
		                sprintf("%s��\n    ��ͨ��������װ����Ҫ����%d�����Ƿ�ͬ�⣿\n"
		                        ESC "��ͬ��\nrepair ! %x# all\n"
		                        ESC "̫���ˣ��Ҳ�������\nCLOSE\n", who->get_name(), allvalue, getoid(who) ) );                
		        return 1;        	
		}
		if (flag==3)
		{
//		        send_user( me, "%c%c%w%s", ':', 1, who->get_char_picid(), 
//		                sprintf("%s��\n    ������������װ����Ҫ����%d�����Ƿ�ͬ�⣿\n"
//		                        ESC "��ͬ��\nrepair !! %x# all\n"
//		                        ESC "̫���ˣ��Ҳ�������\nCLOSE\n", who->get_name(), allvalue, getoid(who) ) );                
		        return 1;        	
		}
		
		me->add_cash2( -allvalue );  me->add_gold_log("repair", allvalue);
		legend = sprintf("���� %s,%d,%s,%s @%s �� 0 %d 0 %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), who->get_name(), allvalue, get_z(me), get_x(me), get_y(me) );
		"/sys/user/cmd"->log_item(legend);
		"/sys/sys/count"->add_use("repair", allvalue);
        	for( i = 0, size = sizeof(inv); i < size; i ++ ) 
        	{
        		if (objectp(inv[i]))
        		{
        			item = inv[i];
        			if( !item->is_equip() ) continue;
//        			if( item->get_equip_type() == HAND_TYPE ) continue;
        			if( item->get_weapon_code() == THROWING ) continue;
        			if( item->get_equip_type() == HAND_TYPE ) continue;
        			if( item->get_equip_type() == FAMILY_TYPE ) continue;
        			if( item->get_max_lasting() < 10 ) continue;
        			if( item->get_lasting() >= item->get_max_lasting() ) continue;
        			if( ( value = item->get_value() ) <= 0 ) continue;
				last = item->get_max_lasting();
				if( flag == 4 )
				{
			        	last = last - (last - item->get_lasting()) /20;
			        	if (item->get_max_lasting() -last<10) last = item->get_max_lasting() - 10;
					
				}
				item->set_max_lasting(last);
				item->set_lasting(last);        			
        		}
        	}		
		"/sys/user/energy"->count_all_prop(me);
		if( city = CITY_D->get_city_object(who) )
		{
		        city->add_tax( value * tax / (100 + tax) );
		        city->add_cash( value * (100 - tax) / (100 + tax) );
		}
		
		
		write_user( me, ECHO "���ó�����װ����%s�������� %d ��", 
			who->get_name(), allvalue );
		
		return 1;		         		
        	 	
        }

        if( !( item = present(arg, me, 1, FAMILY_TYPE) ) ) 
        {
        	inv = me->get_all_equip();
        	for( i = 0, size = sizeof(inv); i < size; i ++ ) 
        	{
        		if (objectp(inv[i])&&arg==sprintf("%x#", getoid(inv[i])))
        		{
        			item = inv[i];
        			break;
        		}
        	}
        	if (!objectp(item)) return 1;    // ���Ҳ�������������
        }

        if( !item->is_equip() )
        {
                notify( item->get_name() + "����װ������������" );
                return 1;
        }
/*        
        if( item->get_equip_type() == HAND_TYPE )
        {
                notify( "û�취����%s��", item->get_name() );
                return 1;
        }
*/        
        if( item->get_weapon_code() == THROWING )
        {
                notify( item->get_name() + "�ǰ�����û�취����" );
                return 1;
        }
        if( item->get_equip_type() == FAMILY_TYPE )
        {
                notify( "û�취����%s��", item->get_name() );
                return 1;
        }     
        if( item->get_equip_type() == HAND_TYPE )
        {
                notify( "û�취����%s��", item->get_name() );
                return 1;
        }            
        if( item->get_max_lasting() < 10 )
        {
                notify( item->get_name() + "�Ѿ��ƾɲ����������������ˡ�" );
                return 1;
        }
        if( item->get_lasting() >= item->get_max_lasting() )
        {
                notify( item->get_name() + "Ŀǰ�ܺã�û�б�Ҫ����" );
                return 1;
        }

        if( ( value = item->get_value() ) < 0 )
        {
                notify( item->get_name() + "���޼�֮����û�취����" );
                return 1;
        }
        else if( value == 0 )
        {
                notify( item->get_name() + "�ǲ�ֵ���ģ�û��Ҫ����" );
                return 1;
        }

        if( item->is_combined() ) value *= item->get_amount();
        value = value - value * item->get_lasting()/item->get_max_lasting();
	if( item->get_equip_type() == HAND_TYPE ) value = 100000;
//        if( flag == 3 || flag== 5 ) value *= 8;    // ��������
	if( flag == 3 || flag== 5 ) return 1;
                

        value += value * tax / 100;        
        if (value<10) value = 10;

        if( me->get_cash() < value )
        {
                notify( "����%sҪ %d �������ϵ��ֽ𲻹���", item->get_name(), value );
                return 1;
        }
        if (flag==2)
        {
                send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), 
                        sprintf("%s��\n    ��ͨ����%s��Ҫ����%d�����Ƿ�ͬ�⣿\n"
                                ESC "��ͬ��\nrepair ! %x# %x#\n"
                                ESC "̫���ˣ��Ҳ�������\nCLOSE\n", who->get_name(), item->get_name(), value, getoid(who), getoid(item) ) );                
                return 1;        	
        }
        if (flag==3)
        {
//                send_user( me, "%c%c%w%s", ':', 1, who->get_char_picid(), 
//                        sprintf("%s��\n    ��������%s��Ҫ����%d�����Ƿ�ͬ�⣿\n"
//                                ESC "��ͬ��\nrepair !! %x# %x#\n"
//                                ESC "̫���ˣ��Ҳ�������\nCLOSE\n", who->get_name(), item->get_name(), value, getoid(who), getoid(item) ) );                
                return 1;        	
        }

        me->add_cash2( -value );  me->add_gold_log("repair", value);
        legend = sprintf("���� %s,%d,%s,%s @%s �� 0 %d 0 %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), who->get_name(), value, get_z(me), get_x(me), get_y(me) );
	"/sys/user/cmd"->log_item(legend);
        "/sys/sys/count"->add_use("repair", value);
        size = item->get_max_lasting();
        if( flag == 4 )
        {
        	size = size - (size - item->get_lasting()) /20;
        	if (item->get_max_lasting() -size<10) size = item->get_max_lasting() - 10;
        }
        item->set_max_lasting(size);
        item->set_lasting(size);

        if( city = CITY_D->get_city_object(who) )
        {
                city->add_tax( value * tax / (100 + tax) );
                city->add_cash( value * (100 - tax) / (100 + tax) );
        }

        write_user( me, ECHO "���ó�%s��%s�������� %d ��", 
		item->get_name(), who->get_name(), value );

        return 1;
}
