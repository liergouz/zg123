
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("�ӷ�����");
        set_picid_1(8708);
        set_picid_2(8708);

        set_level(55);
        set_value(16750);
        set_max_lasting(6399);
        set("dp", 42);
        set("pp", 55);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�ӷ�����";
}
