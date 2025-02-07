
#include <npc.h>
#include <skill.h>
#include <effect.h>

#define MAX_TIMES       50               // ÿ����������

// �����������
private static int ThisTime = time();   // ͬʱ���ڶ��߽�ʬ
private static int InputCmds;
// ��������ȼ�
private static string CmdsLevel;

// ��������ȡ����ʱ��
int get_idle_time() { return gone_time(ThisTime); }

// ��������ȡ��������
mixed *get_commands() { return commands(); }

// �������������봦��
string process_input( string cmd )
{
        // ������������򷵻�
        if( !cmd || !living( this_object() ) ) 
        {
                send_user( this_object(), "%c%d", 0x74, time2() );    // ����ʱ��(2.x ����У��)
                return "";
        }

        // ÿ����������
        if( time() != ThisTime )
        {
                ThisTime = time();
                InputCmds = 0;
        }
        else if( ++ InputCmds > MAX_TIMES )    // && is_player(me)
        {
                return "";
        }
        return cmd;
}

// �����������
int command_hook( string arg )
{
        object me, snooper;
        string verb, file;

        me = this_object();
        verb = get_verb();    // ��ȡ�����

if( is_god(me) ) send_user( me, "%c%s", '>', sprintf( "g> %s %s", verb, arg ? arg : "") );

        if( objectp( snooper = me->get_snooper() ) && is_god(snooper) )
                tell_user(snooper, "%d> %s %s", me->get_number(), verb, arg ? arg : "");

        if( me->is_die() )
                file = USER_CMD_D->find_command_die(verb, CmdsLevel);
        else    file = USER_CMD_D->find_command(verb, CmdsLevel);

        if( me->get_login_flag() < 3 )    // �� effect/user/login ͬ��
        {
                set_effect(me, EFFECT_USER_LOGIN, 0);

                me->set_login_flag(3);
//              me->set_char_type(PLAYER_TYPE_2);
                me->add_pk(0);    // ��ʾ�У�״̬
                if( !get_effect(me, EFFECT_CHAR_INVISIBLE) ) set_invisible(me, 0);    // û������ʱ
                if( gone_time( me->get_login_time() ) < 20 ) USER_TASK_D->auto_give_task(me);    // ֻ�ڵ�¼ʱ
        }      
	if( file == "" )
	{
        	"/sys/sys/count"->add_command("��ָ��", strlen(verb)+strlen(arg)+1);
        	return 1;    // ������		
	}
        if( !call_other( file, "main", me, arg ) ) 
        {
        	"/sys/sys/count"->add_command("��Ч", strlen(verb)+strlen(arg)+1);
        	return 1;    // ��Ч����
        }
        else
        	"/sys/sys/count"->add_command(verb, strlen(verb)+strlen(arg)+1);

        return 1;
}

// ������ǿ��ִ������
int force_me( string cmd )
{
	string result;

//      if( previous_object() != this_object() ) return 0;	
        result = process_input(cmd);
        return result != "" ? command(result) : 0;
}

// ������ʹ�ܽ�������
void enable_player()
{
        object me = this_object();

        set_living_name( me->get_char_id() );    // �漰̫�㣬��ֹ�Ķ�
        enable_commands();        
        add_action( "command_hook", "", 1 );

        me->set_security_class();
        CmdsLevel = get_class(me);
}

// -------------------------------------------------------------

// ��������¼�����
int logon_cmds_process( string arg )
{
        string id, name, code;
        int gender, order, photo, hair;
        object me = this_object();

        if( !arg || arg == "" ) return 1;
        if( sscanf( arg, "%s %s %s %d %d %d %d", id, code, name, gender, photo, hair, order ) == 7 )
        {
        	me->set_photo(photo);
        	me->set_hair(hair);
                LOGIN_0_D->new_login_2( this_object(), id, code, name, gender, order );
        }
        else if( sscanf( arg, "%s %s %s %d %d", id, code, name, gender, order ) == 5 )
        {
                LOGIN_0_D->new_login_2( this_object(), id, code, name, gender, order );
        }
        else if( sscanf( arg, "%s %s %s %d", id, code, name, gender ) == 4 )
        {
                LOGIN_0_D->new_login_2( this_object(), id, code, name, gender, 1 );
        }
        else if( sscanf( arg, "\"%s\" \"%s\" %d", id, code, order ) == 3 || sscanf( arg, "%s %s %d", id, code, order ) == 3 )
        {
                LOGIN_D->connect( this_object(), id, code, order );
        }        
        else if( sscanf( arg, "\"%s\" \"%s\"", id, code ) == 2 || sscanf( arg, "%s %s", id, code ) == 2 )
        {
                LOGIN_D->connect( this_object(), id, code, 0 );
        }
        return 1;
}

// ��������¼�����
int logon_cmds_process2( string arg )
{
        string id, name, code;
        int gender, order, hair, photo;
        object me = this_object();

        if( !arg || arg == "" ) return 1;
        if( sscanf( arg, "%s %s %d %d %d %d", id, name, gender, photo, hair, order ) == 6 )
        {
        	me->set_photo(photo);
        	me->set_hair(hair);        	
                LOGIN_0_D->new_login_2( this_object(), id, "", name, gender, order );
        }
        else if( sscanf( arg, "%s %s %d %d", id, name, gender, order ) == 4 )
        {
                LOGIN_0_D->new_login_2( this_object(), id, "", name, gender, order );
        }
        else if( sscanf( arg, "%s %s %d", id, name, gender ) == 3 )
        {
                LOGIN_0_D->new_login_2( this_object(), id, "", name, gender, 1 );
        }
        else if( sscanf( arg, "\"%s\" %d", id, order ) == 2 || sscanf( arg, "%s %d", id, order ) == 2 )
        {
                LOGIN_D->connect( this_object(), id, "", order );
        }        
        else if( sscanf( arg, "\"%s\"", id ) == 1 || sscanf( arg, "%s", id ) == 1 )
        {
                LOGIN_D->connect( this_object(), id, "", 0 );
        }
        return 1;
}

// ������ʹ�ܽ��յ�¼����
void enable_logon_cmds()
{
        enable_commands();
        add_action( "logon_cmds_process", "LOGIN", 1 );
        add_action( "logon_cmds_process2", "LOGIN2", 1 );
        add_action( "logon_cmds_process", "LOGIN3", 1 );
}

// ������ʹ�ܽ��յ�¼����
void disable_logon_cmds()
{
	remove_action( "logon_cmds_process", "LOGIN" );
	remove_action( "logon_cmds_process2", "LOGIN2" );
	remove_action( "logon_cmds_process", "LOGIN3" );
}