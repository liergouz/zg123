
#include <npc.h>
#include <skill.h>
#include <effect.h>

#define MAX_TIMES       50               // Ã¿ÃëÃüÁîÏÞÖÆ

// ÃüÁî¼ÆÊýÏÞÖÆ
private static int ThisTime = time();   // Í¬Ê±ÓÃÓÚ¶ÏÏß½©Ê¬
private static int InputCmds;
// ¿ÉÓÃÃüÁîµÈ¼¶
private static string CmdsLevel;

// º¯Êý£º»ñÈ¡·¢´ôÊ±¼ä
int get_idle_time() { return gone_time(ThisTime); }

// º¯Êý£º»ñÈ¡¿ÉÓÃÃüÁî
mixed *get_commands() { return commands(); }

// º¯Êý£ºÃüÁîÊäÈë´¦Àí
string process_input( string cmd )
{
        // ¿ÕÃüÁî¡¢ÎÞÉúÃüÔò·µ»Ø
        if( !cmd || !living( this_object() ) ) 
        {
                send_user( this_object(), "%c%d", 0x74, time2() );    // ¶¯×÷Ê±ÖÓ(2.x ·ÖÖÓÐ£Õý)
                return "";
        }

        // Ã¿ÃëÃüÁîÏÞÖÆ
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

// º¯Êý£ºÃüÁî´¦Àí
int command_hook( string arg )
{
        object me, snooper;
        string verb, file;

        me = this_object();
        verb = get_verb();    // »ñÈ¡ÃüÁî¶¯´Ê

if( is_god(me) ) send_user( me, "%c%s", '>', sprintf( "g> %s %s", verb, arg ? arg : "") );

        if( objectp( snooper = me->get_snooper() ) && is_god(snooper) )
                tell_user(snooper, "%d> %s %s", me->get_number(), verb, arg ? arg : "");

        if( me->is_die() )
                file = USER_CMD_D->find_command_die(verb, CmdsLevel);
        else    file = USER_CMD_D->find_command(verb, CmdsLevel);

        if( me->get_login_flag() < 3 )    // Óë effect/user/login Í¬²½
        {
                set_effect(me, EFFECT_USER_LOGIN, 0);

                me->set_login_flag(3);
//              me->set_char_type(PLAYER_TYPE_2);
                me->add_pk(0);    // ÏÔÊ¾£Ð£Ë×´Ì¬
                if( !get_effect(me, EFFECT_CHAR_INVISIBLE) ) set_invisible(me, 0);    // Ã»ÓÐÒþÉíÊ±
                if( gone_time( me->get_login_time() ) < 20 ) USER_TASK_D->auto_give_task(me);    // Ö»ÔÚµÇÂ¼Ê±
        }      
	if( file == "" )
	{
        	"/sys/sys/count"->add_command("ÎÞÖ¸Áî", strlen(verb)+strlen(arg)+1);
        	return 1;    // ÎÞÃüÁî		
	}
        if( !call_other( file, "main", me, arg ) ) 
        {
        	"/sys/sys/count"->add_command("ÎÞÐ§", strlen(verb)+strlen(arg)+1);
        	return 1;    // ÎÞÐ§ÃüÁî
        }
        else
        	"/sys/sys/count"->add_command(verb, strlen(verb)+strlen(arg)+1);

        return 1;
}

// º¯Êý£ºÇ¿ÆÈÖ´ÐÐÃüÁî
int force_me( string cmd )
{
	string result;

//      if( previous_object() != this_object() ) return 0;	
        result = process_input(cmd);
        return result != "" ? command(result) : 0;
}

// º¯Êý£ºÊ¹ÄÜ½ÓÊÕÃüÁî
void enable_player()
{
        object me = this_object();

        set_living_name( me->get_char_id() );    // Éæ¼°Ì«¹ã£¬½ûÖ¹¸Ä¶¯
        enable_commands();        
        add_action( "command_hook", "", 1 );

        me->set_security_class();
        CmdsLevel = get_class(me);
}

// -------------------------------------------------------------

// º¯Êý£ºµÇÂ¼ÃüÁî´¦Àí
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

// º¯Êý£ºµÇÂ¼ÃüÁî´¦Àí
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

// º¯Êý£ºÊ¹ÄÜ½ÓÊÕµÇÂ¼ÃüÁî
void enable_logon_cmds()
{
        enable_commands();
        add_action( "logon_cmds_process", "LOGIN", 1 );
        add_action( "logon_cmds_process2", "LOGIN2", 1 );
        add_action( "logon_cmds_process", "LOGIN3", 1 );
}

// º¯Êý£ºÊ¹ÄÜ½ÓÊÕµÇÂ¼ÃüÁî
void disable_logon_cmds()
{
	remove_action( "logon_cmds_process", "LOGIN" );
	remove_action( "logon_cmds_process2", "LOGIN2" );
	remove_action( "logon_cmds_process", "LOGIN3" );
}