
#include <skill.h>
#include <action.h>
#include <effect.h>

// �����������
int main( object me, string arg )
{
        object file, what;
        string id, item;
        int busy, pf, x, y, which;
        
        if (me->get_ride()) return 1;

/*      if( !is_god(me) && gone_time( me->get_time("pf2") ) < 1 )    // ԭ����Щָ�������ɵ� pf2 XXXX.????
        {
                me->set_time( "pf2", time() );
                notify( "����Ƶ��ʹ��ָ�" );
                return 1;
        }
        me->set_time( "pf2", time() );
*/
/*      if( me->is_store_open() )    // ԭ�򣺰�̯���� pf2 ���е�
        {
                notify( "���ڰ�̯����Ҫ���ġ�" );
                return 1;
        }       */
        if( busy = get_effect(me, EFFECT_CHAR_BUSY) )
        {
                notify( "������æ %d ���ӡ�", busy );
                return 1;
        }
/*        
        if ( gone_time( me->get_login_time())+ me->get_game_time()+2*3600<me->get_double_time())
        {
        	me->set_double_time(gone_time( me->get_login_time())+ me->get_game_time()+2*3600);
        }        
*/        
        if(     get_effect(me, EFFECT_CHAR_FAINT) 
        ||      get_effect(me, EFFECT_CHAR_FAINT_2)
        ||      get_effect(me, EFFECT_SLEEP)
        ||      get_effect(me, EFFECT_MAGIC_4243)
        ||      get_effect(me, EFFECT_CHAR_FREEZE)
        ||      get_effect(me, EFFECT_CHAR_DREAM_1)
        ||      get_effect(me, EFFECT_CHAR_DREAM) ) return 1;

        if( !arg ) return 1;

        if( me->get_char_action() != DEFAULT_ACT ) me->set_char_action(DEFAULT_ACT);    // �ָ�վ��״̬(��ֹС����)

        if( sscanf( arg, "%d %d,%d", pf, x, y ) == 3 )
        {
                if(   ( file = load_object( SKILL->get_perform_file(pf) ) )
                &&      file->get_perform_type() != ON_ME_7 )
                        file->main(me, 0, x, y, "");
        }
        else if( sscanf( arg, "%d (%d)", pf, which ) == 2 )
        {
                if(   ( file = load_object( SKILL->get_perform_file(pf) ) )
                &&      file->get_perform_type() == ON_ITEM_7
                &&    ( what = number_present(me, which, 1, MAX_CARRY) ) ) 
                        file->main(me, what, 0, 0, "");
        }
        else if( sscanf( arg, "%d %s %d", pf, id, which ) == 3 )
        {
                if(   ( file = load_object( SKILL->get_perform_file(pf) ) )
                &&      file->get_perform_type() == ON_ITEM_8
                &&    ( what = find_char(id) )
                &&      number_present(what, which, 1, MAX_CARRY) )
                        file->main(me, what, 0, 0, sprintf("%d", which) );
        }
        else if( sscanf( arg, "%d %s", pf, arg ) == 2 )
        {    	
                if(   ( file = load_object( SKILL->get_perform_file(pf) ) )
                &&    ( file->get_perform_type() == ON_CHAR_7 || file->get_perform_type() == ON_TALISMAN )
                &&    ( what = find_char(arg) ) )
                        file->main(me, what, 0, 0, "");
        }
        else if( sscanf( arg, "%d.%s", pf, arg ) == 2 )
        {
                if(   ( file = load_object( SKILL->get_perform_file(pf) ) )
                &&    ( file->get_perform_type() == ON_ME_7 || file->get_perform_type() == ON_TALISMAN ) )
                        file->main(me, 0, 0, 0, arg);
        }
        else if( pf = to_int(arg) )
        {
                if(   ( file = load_object( SKILL->get_perform_file(pf) ) )
                &&    ( file->get_perform_type() == ON_ME_7 || file->get_perform_type() == ON_TALISMAN ) )
                        file->main(me, 0, 0, 0, "");
        }

        return 1;
}
