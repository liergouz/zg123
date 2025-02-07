// guarder ��������������

#include <ansi.h>
#include <action.h>

// �������Ի�����
void do_look( object who, object me )
{
        object city;
        string name1, name2;
        string cmd, cmd2, result;

        name1 = who->get_city_name();
        name2 = me->get_city_name();

        if( stringp(name1) && stringp(name2) && name1 == name2 )
        {
                cmd = sprintf( "talk %x# enter\n", getoid(me) );
                cmd2 = sprintf( "talk %x# record\n", getoid(me) );
                send_user( who, "%c%s", ':', me->get_name() + "��\n    "+"/quest/word"->get_country_word(me)+"\n    " + who->get_name() + "������ʲô���飿\n" 
                        ESC "��Ҫ���ǡ�\n" + cmd +
                        ESC "��"+name2+"��Ϊ�ҵĻسǵ㡣\n" + cmd2 +
                        ESC "�뿪��\nCLOSE\n" );
        }
        else if( city = CITY_D->get_city_object(me) )
        {
                cmd = sprintf( "talk %x# enter\n", getoid(me) );
                cmd2 = sprintf( "talk %x# record\n", getoid(me) );
                result = sprintf( "%s��\n    "+"/quest/word"->get_country_word(me)+"\n", me->get_name());
                send_user( who, "%c%s", ':', result +
                        ESC "��Ҫ���ǡ�\n" + cmd +
                        ESC "��"+name2+"��Ϊ�ҵĻسǵ㡣\n" + cmd2 +
                        ESC "�뿪��\nCLOSE\n" );
        }
}

// �������Ի�����
void do_look_2( object who, object me )
{
        string cmd = sprintf( "talk %x# out\n", getoid(me) );
        string cmd2 = sprintf( "talk %x# record\n", getoid(me) );
        send_user( who, "%c%s", ':', me->get_name() + "��\n    "+"/quest/word"->get_country_word(me)+"\n    " + who->get_name() + "������ʲô���飿\n" 
                ESC "��Ҫ���ǡ�\n" + cmd +
                ESC "��"+me->get_city_name()+"��Ϊ�ҵĻسǵ㡣\n" + cmd2 +
                ESC "�뿪��\nCLOSE\n" );
}

// �������Ի�����
void do_look_3( object who, object me )
{
        string name;
        int z, x, y, p;

        if(     who->get_quest("escort.flag")    // ��������
        &&      stringp( name = who->get_quest("escort.name") )    // ��������
        &&    ( p = QUEST_ESCORT->get_xy_point(name) ) )    // ȷ�д���
        {
                z = p / 1000000;  x = ( p % 1000000 ) / 1000;  y = p % 1000;

                if( get_z(me) == z )    // ͬһ����
                {
                        send_user( who, "%c%s", ':', sprintf( me->get_name() + 
                                "��\n���������ʶ����ˣ�������ʱ�򣬿���%s��(%d,%d)����������������ʲô�Ƶġ�\n", name, x, y ) );

                        send_user( who, "%c%c%d%w%w", 0x54, 12, getoid(who), x, y );    // ���� getoid(who)
                        who->set_task_xy(p);

                        return;
                }
        }

        send_user( who, "%c%s", ':', me->get_name() + "\n    "+"/quest/word"->get_country_word(me) );
}

// ��������Ǵ���
void do_enter( object who, object me )
{
        object city, npc;
        string name1, name2;
        int z, x, y, p;

        name1 = who->get_city_name();
        name2 = me->get_city_name();

        switch( name2 )
        {
  case "���" : z = 10;  p = get_jumpin( z, me->get("in") );  break;
  case "����" : z = 20;  p = get_jumpin( z, me->get("in") );  break;
  case "�Թ�" : z = 30;  p = get_jumpin( z, me->get("in") );  break;
  case "κ��" : z = 40;  p = get_jumpin( z, me->get("in") );  break;
  case "�ع�" : z = 50;  p = get_jumpin( z, me->get("in") );  break;
  case "����" : z = 60;  p = get_jumpin( z, me->get("in") );  break;
  case "���" : z = 70;  p = get_jumpin( z, me->get("in") );  break;
      default :
  case "�ܹ�" : z = 80;  p = get_jumpin( z, me->get("in") );  break;
        }

        if( !p )
        {
                send_user(who, "%c%s", '!', "�������̫�����ˡ���");
                return;
        }
        if( objectp( npc = who->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // Ѱ��������
        {
                send_user(who, "%c%s", '!', npc->get_name()+"���֣������ж��ܵ�Ӱ�졣");
                return;
        }

        if( stringp(name1) && stringp(name2) && name1 == name2 )
        {
                x = p / 1000;  y = p % 1000;

                if(   ( npc = who->get_quest("escort.npc") )    // ��������
                &&      npc->get_owner() == who
                &&      inside_screen_2(me, npc) )    // ��������
                        npc->add_to_scene( z, x, y, get_d(who) );

                if( p = get_valid_xy( z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK ) )
                {
                        who->add_to_scene( z, p / 1000, p % 1000, get_d(who) );
                }
        }
        else if( city = CITY_D->get_city_object(me) )
        {

                x = p / 1000;  y = p % 1000;

                if(   ( npc = who->get_quest("escort.npc") )    // ��������
                &&      npc->get_owner() == who
                &&      inside_screen_2(me, npc) )    // ��������
                        npc->add_to_scene( z, x, y, get_d(who) );

                if( p = get_valid_xy( z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK ) )
                {
                        who->add_to_scene( z, p / 1000, p % 1000, get_d(who) );
                }
        }
}

// ���������Ǵ���
void do_out( object who, object me )
{
        object npc;
        int z, x, y, p;

        switch( me->get_city_name() )
        {
  case "���" : z = 10;  p = get_jumpin( z, me->get("out") ); 
//                who->set_latest_city( z * 100 + me->get("out") ); 
                break;
  case "����" : z = 20;  p = get_jumpin( z, me->get("out") );  
//                who->set_latest_city( z * 100 + me->get("out") ); 
                break;
  case "�Թ�" : z = 30;  p = get_jumpin( z, me->get("out") );  
//                who->set_latest_city( z * 100 + me->get("out") ); 
                break;
  case "κ��" : z = 40;  p = get_jumpin( z, me->get("out") );  
//                who->set_latest_city( z * 100 + me->get("out") ); 
                break;
  case "�ع�" : z = 50;  p = get_jumpin( z, me->get("out") );  
//                who->set_latest_city( z * 100 + me->get("out") ); 
                break;
  case "����" : z = 60;  p = get_jumpin( z, me->get("out") );  
//                who->set_latest_city( z * 100 + me->get("out") ); 
                break;
  case "���" : z = 70;  p = get_jumpin( z, me->get("out") );  
//                who->set_latest_city( z * 100 + me->get("out") ); 
                break;
      default :
  case "�ܹ�" : z = 80;  p = get_jumpin( z, me->get("out") );  
//                who->set_latest_city( z * 100 + me->get("out") );    // �سǷ�
                break;
        }

        if( !p )
        {
                send_user(who, "%c%s", '!', "���ſں���̫�����ˡ���");
                return;
        }
        if( objectp( npc = who->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // Ѱ��������
        {
                send_user(who, "%c%s", '!', npc->get_name()+"���֣������ж��ܵ�Ӱ�졣");
                return;
        }

        x = p / 1000;  y = p % 1000;

        if(   ( npc = who->get_quest("escort.npc") )    // ��������
        &&      npc->get_owner() == who
        &&      inside_screen_2(me, npc) )    // ��������
                npc->add_to_scene( z, x, y, get_d(who) );

        if( p = get_valid_xy( z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK ) )
        {
                who->add_to_scene( z, p / 1000, p % 1000, get_d(who) );
        }
}

// ���������Ǵ���
void do_record( object who, object me )
{
        object npc;
        int z, x, y, p;

        switch( me->get_city_name() )
        {
	  case "���" : z = 10;  p = get_jumpin( z, me->get("out") ); 
	                who->set_latest_city( z * 100 + me->get("out") ); 
	                break;
	  case "����" : z = 20;  p = get_jumpin( z, me->get("out") );  
	                who->set_latest_city( z * 100 + me->get("out") ); 
	                break;
	  case "�Թ�" : z = 30;  p = get_jumpin( z, me->get("out") );  
	                who->set_latest_city( z * 100 + me->get("out") ); 
	                break;
	  case "κ��" : z = 40;  p = get_jumpin( z, me->get("out") );  
	                who->set_latest_city( z * 100 + me->get("out") ); 
	                break;
	  case "�ع�" : z = 50;  p = get_jumpin( z, me->get("out") );  
	                who->set_latest_city( z * 100 + me->get("out") ); 
	                break;
	  case "����" : z = 60;  p = get_jumpin( z, me->get("out") );  
	                who->set_latest_city( z * 100 + me->get("out") ); 
	                break;
	  case "���" : z = 70;  p = get_jumpin( z, me->get("out") );  
	                who->set_latest_city( z * 100 + me->get("out") ); 
	                break;
	      default :
	  case "�ܹ�" : z = 80;  p = get_jumpin( z, 10 );  
	                who->set_latest_city( z * 100 + 10 );    // �سǷ�
	                break;
        }	
        write_user( who, ECHO "���������µĻسǵ㡣\n" );
}	