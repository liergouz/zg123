
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("�ɻ���");
        set_picid_1(8810);
        set_picid_2(8810);

        set_level(45);
        set_value(7600);
        set_max_lasting(7799);
        set("dp", 22);
        set("sp", 25);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�ɻ���";
}
