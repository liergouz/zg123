
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��Ե��");
        set_picid_1(8810);
        set_picid_2(8810);

        set_level(110);
        set_value(23500);
        set_max_lasting(13299);
        set("dp", 24);
        set("sp", 118);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��Ե��";
}
