
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("�ǳ���");
        set_picid_1(8808);
        set_picid_2(8808);

        set_level(120);
        set_value(30800);
        set_max_lasting(13399);
        set("dp", 56);
        set("sp", 66);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�ǳ���";
}
