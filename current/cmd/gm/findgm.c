
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <map.h>
inherit DBASE_F;

inherit SAVE_F;

int * place = ({ 80, 20, 10, 70, 60, 50, 40, 30, 139, 271 });

void create() 
{
	restore();
}

// ������ȡ�����ļ���
string get_save_file() { return "data/city/findgm"SAVE_EXTENSION; }

// �����������
int main( object me, string arg )
{
	int i, size, p, x, y, z, type;
	object * npcs, npc, who, map;
	string arg2;
        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }
        if( !arg )
        {
              	send_user( me, "%c%s", ':', "������ʲô�أ�\n"
              		ESC "���ý�Ʒ����\n" + "findgm setbonus\n" +
              		ESC "����GM���ֵĵ�ͼ\n" + "findgm setmap\n" +
              		ESC "��ʼѰ�ңǣ͵Ļ\n" + "findgm start\n" +
              		ESC "����Ѱ�ңǣ͵Ļ\n" + "findgm end\n" +
              		ESC "��ʾʣ��ǣ͵�λ��\n" + "findgm list\n" +
              		ESC "ȡ��\nCLOSE" );
              	return 1;        	
	}
	who = this_object();
	switch(arg)	
	{
	case "start":
		npcs = get("npcs");		
		if (npcs!=0 && sizeof(npcs)!=0)
		{
			notify( "�ϴ�Ѱ��gm�Ļ��δ������" );
			return 1;
		}		
		who->add_save("gm_time", 1);
		who->save();
		npcs = ({ });
		npc = new ("/npc/party/gm2");
		size = sizeof(place);
		z = who->get_save("map");
		if (z==0) z = 80;		
		if ( (p = get_xy_point(z, IS_CHAR_BLOCK))|| (p = get_jumpin(z, -1)) )
		{
			x = p / 1000;  y = p % 1000;
	                if( p = get_valid_xy( z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK ) )
	                {
	                        npc->add_to_scene( z, p / 1000, p % 1000, get_d(me), 40991, 40992, 40991, 40992 );
	                        npcs += ({ npc });
	                }
	                map = get_map_object(z);
	                arg2 = map->get_name();			
		}
		else		
		{
			notify( "��ͼ���ò���" );
			return 1;
		}
		for (i=0;i<9;i++)
		{
			npc = new ("/npc/party/gm");
			size = sizeof(place);

			if ( (p = get_xy_point(z, IS_CHAR_BLOCK))|| (p = get_jumpin(z, -1)) )
			{
				x = p / 1000;  y = p % 1000;
		                if( p = get_valid_xy( z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK ) )
		                {
		                        npc->add_to_scene( z, p / 1000, p % 1000, get_d(me), 40991, 40992, 40991, 40992 );
		                        npcs += ({ npc });
		                }			
			}
				
		}
		set("npcs", npcs);
		notify( "Ѱ��gm�Ļ�ɹ�����"+arg2+"��ʼ��" );
		return 1;
		break;
	case "end":	
		npcs = get("npcs");
		if (npcs==0) return 1;
		npcs -= ({ 0 });	
		size = sizeof(npcs);
		set("npcs", npcs);
		if (size==0) return 1;
		for (i=0;i<size;i++)
		{
			npcs[i]->remove_from_scene();
			destruct(npcs[i]);        
		}
		set("npcs", 0);
		notify( "Ѱ��gm�Ļ�ɹ��ؽ�����" );	
		return 1;	
		break;;
	case "list":
		npcs = get("npcs");
		if (npcs==0) return 1;
		npcs -= ({ 0 });	
		size = sizeof(npcs);
		set("npcs", npcs);
		if (size==0) return 1;	
		for (i=0;i<size;i++)
		{
			send_user( me, "%c%s", '>', sprintf("%s(%x#)��������%d %d,%d", npcs[i]->get_name(), getoid(npcs[i]), get_z(npcs[i]), get_x(npcs[i]), get_y(npcs[i])));     
		}	
		return 1;
		break;
	case "setbonus":
              	send_user( me, "%c%s", ':', "��ѡ���������Ԫ����Ľ�Ʒ��\n"
              		ESC "ս����\n" + "findgm setbonus 1\n" +
              		ESC "ս���Ž�\n" + "findgm setbonus 2\n" +
              		ESC "Ѫʯ\n" + "findgm setbonus 3\n" +
              		ESC "��ʯ\n" + "findgm setbonus 4\n" +
              		ESC "���ӱ���\n" + "findgm setbonus 5\n" +
              		ESC "������\n" + "findgm setbonus 6\n" +
              		ESC "��ңɢ\n" + "findgm setbonus 7\n" +
              		ESC "���ĵ�\n" + "findgm setbonus 8\n" +
              		ESC "ȡ��\nCLOSE" );
		return 1;
		break;
	case "setmap":
              	send_user( me, "%c%s", ':', "��ѡ����ͼ��\n"
              		ESC "�ܹ�\n" + "findgm setmap 80\n" +
              		ESC "����\n" + "findgm setmap 20\n" +
              		ESC "���\n" + "findgm setmap 10\n" +
              		ESC "���\n" + "findgm setmap 70\n" +
              		ESC "����\n" + "findgm setmap 60\n" +
              		ESC "�ع�\n" + "findgm setmap 50\n" +
              		ESC "κ��\n" + "findgm setmap 40\n" +
              		ESC "�Թ�\n" + "findgm setmap 30\n" +
              		ESC "����\n" + "findgm setmap 21\n" +
              		ESC "��¹\n" + "findgm setmap 271\n" +
              		ESC "ȡ��\nCLOSE" );
		return 1;
		break;	
	}	  				
	sscanf(arg, "%s %d", arg2, type);
	switch(arg2)
	{
	case "setbonus":
		who->set_save("bonus", type);
		who->save();	
		notify( "�����˻�Ľ���" );	
		break;
	case "setmap":
		p = get_jumpin(type, 10);
		if (p==0)
		{
			notify( "����ˢ�ֵ�ͼ��������Ϊ���ͼ��" );	
			return 1;
		}
		who->set_save("map", type);
		who->save();	
		notify( "�����˻��ͼ" );	
		break;		
	}	             	
	return 1;
}
	