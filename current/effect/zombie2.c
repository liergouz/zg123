
#include <effect.h>

// ���������ķ���(�ΣУ�)
void into_effect_2( object me )
{
        object who, *zombie;

        set_effect(me, EFFECT_NPC_ZOMBIE_2, 10);

        if( objectp( who = me->get_owner() ) && who->is_user() )
        {
                if( who->get_mp() >= 16 )
                {
                        who->add_mp(-16);
                }
                else
                {
                	send_user(who, "%c%c%d", 0x2c, 1, getoid(me) );
                        me->remove_from_scene();
                        if( arrayp( zombie = who->get("zombie") ) )
                        {
                                zombie -= ({ me, 0 });
                                who->set("zombie", zombie);
                        }
                        destruct(me);
                }
        }
/*      else    // �� logout Ч������ע��
        {
                me->remove_from_scene();
                destruct(me);
        }       */
}
