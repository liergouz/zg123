
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("�����ñ");
        set_picid_1(6605);
        set_picid_2(6605);

        set_level(60);
        set_value(23500);
        set_max_lasting(7299);
        set("dp", 44);
        set("pp", 69);

        setup();

        set_gender(2);
        set_head_code(54);
}

// ��������ȡ����
string get_desc()
{
        return "�����ñ";
}
