
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8810);
        set_picid_2(8810);

        set_level(100);
        set_value(28500);
        set_max_lasting(8299);
        set("dp", 22);
        set("sp", 39);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
