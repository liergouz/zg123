
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��˿����");
        set_picid_1(8714);
        set_picid_2(8714);

        set_level(60);
        set_value(12600);
        set_max_lasting(8499);
        set("dp", 50);
        set("pp", 50);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��˿����";
}
