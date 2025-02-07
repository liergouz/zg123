
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <skill.h>
#include <action.h>

inherit OFFICER;

void do_welcome( string arg );

// ��������ȡ��������
int get_char_picid() { return 6009; }

// ���������촦��
void create()
{
        set_name( "�ٺ�����" );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));    
        setup();     
}

void do_look( object who )
{
        int status;
        object me = this_object();
        send_user( who, "%c%c%s", ':', 2,
                sprintf("%s��\n    ��ϲ�㣬��ô���ͨ���˿γ̿��飬һ����ò�����ʦ�Ľ����ɣ�������ҽ�����������Ǹ�������ѽ������������浻ݣ�һֱ�������㽵�Ŀ�갡����\n    �������Բ������������ˡ�\n"
                ESC "����\ntalk %x# welcome.1", me->get_name(), getoid(me) ) );        
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int date, p, z, x, y, oldz, i, size, flag;
        object who, obj, oldcity, *inv, *gift;
        who = this_player();
        who->set_time( "talk",  0);                             
        flag = to_int(arg);
        switch(flag)
        {
        case 1:
                send_user( who, "%c%c%s", ':', 2,
                        sprintf("%s��\n    ���ֵ�ʱ�����Ƕ��ݵģ���ô���Ҫ�ֱ��һ������᲻�á����������ٱ�֮ǰ��һ�����⡭���뿪�������ͻᵽ��һ����" HIY "���ִ�" NOR "��С��ׯ����" HIY "үү" NOR "��ס�������Ҳ������үү����к��ˣ�ֻҪ����������Ž������Ϳ����ˣ�����������ʲô���ѣ�������үү��̣������������ġ�\n"
                        ESC "����\ntalk %x# welcome.2", me->get_name(), getoid(me) ) );                        
                break;
        case 2:
                send_user( who, "%c%c%s", ':', 2,
                        sprintf("%s��\n    ���ͷ������Ͼ�Ҫ�����ˣ���Ҫ���ţ������������˫�ۡ���ʼ�ޡ�����\n"
                        ESC "�ر�\ntalk %x# welcome.3", me->get_name(), getoid(me) ) );                        
                break;
        case 3:                             
                send_user( who, "%c%d", ':', 0);
                  // ������ֵ�¼��־                
                who->delete_save("fighter.status");
                // ������ϵ���Ʒ
                gift = ({ });
                inv = who->get_all_equip();
                inv -= ({ 0});
                for( i = 0, size = sizeof(inv); i < size; i ++ )
                {
                        if (inv[i]->get_value()==0)
                        {
                                gift += ({ inv[i] });
                        }
                }        
                inv = all_inventory(who, 1, MAX_CARRY);
                inv -= ({ 0});
                for( i = 0, size = sizeof(inv); i < size; i ++ )
                {
                        if (inv[i]->get_value()==0)
                        {
                                gift += ({ inv[i] });
                        }
                }
                for( i = 0, size = sizeof(gift); i < size; i ++ )
                {
                        gift[i]->remove_from_user();
                        destruct(gift[i]);                        
                }
                USER_ENERGY_D->count_all_prop(who);
                oldz = get_z(who);
                oldcity = get_map_object(oldz);                
        
                MAP_D->add_to_void(who);    // ���� VOID ����  // ���ִ壡
                send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(who), 
                        51141, 1, OVER_BODY, 51142, 1, OVER_BODY, 51143, 1, UNDER_FOOT, 51144, 1, UNDER_FOOT, PF_ONCE );
                who->delete_save_2("Newbie");    // "Newbie.Login"
                NEWBIE->destruct_virtual_map(oldcity, oldz);
                
                break;
        }
}