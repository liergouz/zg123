
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(120);
        set_value(30800);
        set_max_lasting(13399);
        set("dp", 56);
        set("sp", 70);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
