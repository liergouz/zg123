
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("��ԭ����");
        set_picid_1(8656);
        set_picid_2(8656);

        set_level(110);
        set_value(77000);
        set_max_lasting(8199);
        set("cp", 0);
        set("pp", 112);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ԭ����";
}
