
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("��˪����");
        set_picid_1(8705);
        set_picid_2(8705);

        set_level(40);
        set_value(11500);
        set_max_lasting(5899);
        set("dp", 28);
        set("pp", 42);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��˪����";
}
